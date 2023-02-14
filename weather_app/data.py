import requests
import pandas as pd


# kullanıcı isteğine göre url düzenle


def get_url(city: str, api_key: str):

    url = f"https://api.openweathermap.org/data/2.5/forecast?q={city}&APPID={api_key}&units=metric"
    return url

# sayfayı al


def get_page(city: str, api_key: str):
    url = get_url(city, api_key)
    page = requests.get(url)
    content = page.json()
    return content

# sayfayı aldıktan sonra gerekli olan dataları çek ve excel yazdır


def get_data(city: str, api_key: str,):

    country = get_page(city, api_key)["city"]["country"]
    province = get_page(city, api_key)["city"]["name"]
    description = get_page(city, api_key)["list"]

    desc_list = []
    temp_list = []
    time_list = []

    for desc in description:
        desc_list.append(desc["weather"][0]["description"])
        temp_list.append(desc["main"]["temp"])
        time_list.append(desc["dt_txt"])

    result = {"Ülke": country, "İl": province,
              "Zaman": time_list, "Açıklama": desc_list}

    df = pd.DataFrame(result)
    results = df.to_html(index=False)
    return results
