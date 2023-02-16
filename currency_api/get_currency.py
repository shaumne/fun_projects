from bs4 import BeautifulSoup
import requests


def get_currency(from_: str, to: str):
    from_ = from_.upper()
    to = to.upper()
    url = f"https://www.x-rates.com/calculator/?from={from_}&to={to}&amount=1"

    content = requests.get(url).text
    soup = BeautifulSoup(content, "html.parser")
    value = soup.find("span", class_="ccOutputRslt")
    print(value.text)
    return value.text
