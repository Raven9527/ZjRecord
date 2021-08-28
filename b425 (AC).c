#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define IMAGE_SIZE 300

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct CircleMosaic_s
{
    int px;
    int py;
    int r;
}CircleMosaic;
typedef struct Pixel_s
{
    int r;
    int g;
    int b;
}Pixel;
typedef struct Image_s
{
    Pixel pixels[IMAGE_SIZE][IMAGE_SIZE];
    int width;
    int height;
}Image;
void MainProgram();
void InputMasaic(CircleMosaic*);
void InputImage(Image*);
void InputPixel(Pixel*);
void ProcessMosaic(Image*, CircleMosaic*);
int ComputeDistance(int, int, int, int);
Pixel ComputeAvgPixel(Image*, CircleMosaic*, int, int, int);
void SetPixel(Pixel*, Pixel*); // b 設置給 a
void CopyImage(Image*, Image*); // b 複製到 a
void PrintImage(Image*);
int RoundInt(double);

// Main Region
int main()
{
    #if TEST_FLAG
        TestProgram();
    #else
        MainProgram();
    #endif

    #if PAUSE_FLAG
        system("pause");
    #endif

    return 0;
}

void MainProgram()
{
    Image image;
    CircleMosaic mosaic;
    InputMasaic(&mosaic);
    InputImage(&image);
    ProcessMosaic(&image, &mosaic);
    PrintImage(&image);
}

void InputMasaic(CircleMosaic *mosaic)
{
    scanf("%d %d %d", &(mosaic->px), &(mosaic->py), &(mosaic->r));
}

void InputImage(Image *image)
{
    int i, j;
    scanf("%d %d", &(image->width), &(image->height));
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            InputPixel(&image->pixels[i][j]);
        }
    }
}

void InputPixel(Pixel *pixel)
{
    scanf("%d %d %d", &(pixel->r), &(pixel->g), &(pixel->b));
}

void ProcessMosaic(Image *image, CircleMosaic *mosaic)
{
    if (mosaic->r < 0)
        return;
    
    Image tempImage;
    CopyImage(&tempImage, image);
    int i, j;
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            if (ComputeDistance(mosaic->px, mosaic->py, j, i) <= (mosaic->r * mosaic->r)) // x橫向 與j (width) 配對
            {
                Pixel avgPixel = ComputeAvgPixel(image, mosaic, j, i, 10);
                SetPixel(&(tempImage.pixels[i][j]), &avgPixel);
            }
            else
            {
                SetPixel(&(tempImage.pixels[i][j]), &(image->pixels[i][j]));
            }
        }
    }

    CopyImage(image, &tempImage);
}

void SetPixel(Pixel *masterPixel, Pixel *customerPixel)
{
    masterPixel->r = customerPixel->r;
    masterPixel->g = customerPixel->g;
    masterPixel->b = customerPixel->b;
}

int ComputeDistance(int x1, int y1, int x2, int y2)
{
    int x = x2 - x1, y = y2 - y1;
    return ((x * x) + (y * y));
}

Pixel ComputeAvgPixel(Image *image, CircleMosaic *mosaic, int startX, int startY, int range)
{
    int i, j;
    Pixel avgPixel = {0, 0, 0};
    int pixelCount = 0;
    for (i = startY - (range / 2); i <= startY + (range / 2); i++)
    {
        for (j = startX - (range / 2); j <= startX + (range / 2); j++)
        {
            if (i >= 0 && i < image->height && j >= 0 && j < image->width)
            {
                avgPixel.r += image->pixels[i][j].r;
                avgPixel.g += image->pixels[i][j].g;
                avgPixel.b += image->pixels[i][j].b;
                pixelCount++;
            }
        }
    }
    double r = ((double)avgPixel.r) / ((double)pixelCount);
    double g = ((double)avgPixel.g) / ((double)pixelCount);
    double b = ((double)avgPixel.b) / ((double)pixelCount);
    avgPixel.r = (int)(RoundInt(r));
    avgPixel.g = (int)(RoundInt(g));
    avgPixel.b = (int)(RoundInt(b));
    return avgPixel;
}

void CopyImage(Image *aImage, Image *bImage)
{
    int i, j;
    for (i = 0; i < bImage->height; i++)
    {
        for (j = 0; j < bImage->width; j++)
        {
            aImage->pixels[i][j] = bImage->pixels[i][j];
        }
    }
    aImage->width = bImage->width;
    aImage->height = bImage->height;
}

void PrintImage(Image *image)
{
    int i, j;
    printf("%d %d\n", image->width, image->height);
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            printf("%d %d %d ", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
        }
        printf("\n");
    }
}

int RoundInt(double k)
{
    return (int)(k + 0.5);
}

#if TEST_FLAG
// Test Region
int AssertPixelEquals(Pixel pixel1, Pixel pixel2)
{
     return pixel1.r == pixel2.r && pixel1.g == pixel2.g && pixel1.b == pixel2.b;
}
int TestCase1()
{
    Image image = { { { {1, 2, 3} }, { {4, 5, 6} } }, 1, 2};
    image.width = 1;
    image.height = 2;
    CircleMosaic mosaic = {0, 1, 2};
    Pixel exceptPixel[10][10] = { { {3, 4, 5} }, { {3, 4, 5} } };
    ProcessMosaic(&image, &mosaic);
    PrintImage(&image);
    return AssertPixelEquals(image.pixels[0][0], exceptPixel[0][0]) && AssertPixelEquals(image.pixels[1][0], exceptPixel[1][0]);
}
int TestCaseRound()
{
    int flag1 = AssertIntegerEquals(3, RoundInt(2.5));
    int flag2 = AssertIntegerEquals(2, RoundInt(2.4));
    int flag3 = AssertIntegerEquals(2, RoundInt(2.0));
    int flag4 = AssertIntegerEquals(2, RoundInt(1.9));
    int flag5 = AssertIntegerEquals(1, RoundInt(0.5));
    int flag6 = AssertIntegerEquals(0, RoundInt(0.1));

    return flag1 && flag2 && flag3 && flag4 && flag5 && flag6;
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCaseRound());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif