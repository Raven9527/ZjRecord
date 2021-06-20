import requests
url = "https://data.ntpc.gov.tw/api/datasets/71CD1490-A2DF-4198-BEF1-318479775E8A/json?page=1&size=300"
r = requests.get(url)
json_file = r.json()
for json in json_file:
    if json['sno'] == '1417':
        print(json)
print("get tot done")
