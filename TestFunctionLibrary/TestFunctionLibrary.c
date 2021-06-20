int OutputTest(int outputCase, int flag)
{
    if (flag)
        printf("case %d: pass\n", outputCase);
    else
        printf("case %d: fail\n", outputCase);
    return !flag;
}

int AssertTrue(int flag)
{
    if (flag)
        return 1;
    else
        return 0;
}

int AssertIntegerEquals(int except, int active)
{
    if (except == active)
        return 1;
    else
        return 0;
}

int AssertLongLongIntegerEquals(long long except, long long active)
{
    if (except == active)
        return 1;
    else
        return 0;
}