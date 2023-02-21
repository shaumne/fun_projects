import requests
import pandas as pd


def get_products(url, params):
    """
    Get a list of products from a WooCommerce REST API.

    Args:
    url (str): The base URL of the WooCommerce store's REST API.
    params (dict): A dictionary of parameters to pass to the API request.

    Returns:
    list: A list of product dictionaries.
    """

    # Make the API request to get the list of products.
    response = requests.get(url, params=params)

    # Convert the response to JSON and extract the list of products.
    products = response.json()

    return products


def get_product_data(product):
    """
    Extract product data from a product dictionary.

    Args:
    product (dict): A dictionary representing a product.

    Returns:
    dict: A dictionary of product data.
    """

    # Extract the product data from the dictionary.
    title = product['name']
    description = product['description']
    product_type = product['type']
    slug = product['slug']
    link = product["permalink"]
    price = product["regular_price"]
    sku = product["sku"]
    category = product["categories"]
    last_category = category[-1]
    last_slug = last_category["slug"]
    attributes = product["attributes"]
    img = product["images"]
    qty = product["stock_quantity"]

    # Extract the attribute names and options as lists.
    a_name = [attribute['name'] for attribute in attributes]
    a_op = [attribute['options'] for attribute in attributes]

    # Extract the image URLs as a list.
    imgs = [d["src"] for d in img]

    # Extract the tag from the last category slug.
    tag = last_slug.split("-")[0]

    # Convert the attribute names, options, and image URLs to strings.
    options = str(a_op).translate(str.maketrans('', '', "[]'"))
    name = str(a_name).translate(str.maketrans('', '', "[]'"))
    image = str(imgs).translate(str.maketrans('', '', "[]'"))

    # Create a dictionary of product data and return it.
    product_data = {
        "slug": slug,
        "title": title,
        "content": description,
        "vendor": vendor,
        "category": last_slug,
        "type": product_type,
        "Price": price,
        "Sku": sku,
        "img": image,
        "tag": tag,
        "Qty": qty,
        "Option1 Name": name,
        "Option1 Value": options
    }

    return product_data


if __name__ == "__main__":
    # Set the API parameters and vendor name.
    url = "https://urwoocomerce.com/wp-json/wc/v3/products"
    params = {
        "consumer_key": "your_consumer_key",
        "consumer_secret": "your_consumer_secret",
        "per_page": 100,
        "status": "publish",
        "fields": "id,name,price,regular_price,sale_price,stock_quantity,images,categories,tags,variations"
    }
    vendor = "your_vendor"

    # Get the list of products from the API.
    products = get_products(url, params)

    # Extract the product data from each product and store it in a list.
    data = [get_product_data(product) for product in products]

    # Convert the list of dictionaries to a pandas DataFrame.
    df = pd.DataFrame(data)

    # create an empty DataFrame
    all_df = pd.DataFrame()

    # convert to the Shopify format
    all_df["Handle"] = df["slug"]
    all_df["Title"] = df["title"]
    all_df["Body (HTML)"] = df["content"]
    all_df["Vendor"] = "your_vendor"
    all_df["Product Category"] = ""
    all_df["Type"] = ""
    all_df["Tags"] = df["tag"]
    all_df["Published"] = ""
    all_df["Option1 Name"] = df["Option1 Name"]
    all_df["Option1 Value"] = df["Option1 Value"]
    all_df["Option2 Name"] = ""
    all_df["Option2 Value"] = ""
    all_df["Option3 Name"] = ""
    all_df["Option3 Value"] = ""
    all_df["Variant SKU"] = df["Sku"]
    all_df["Variant Grams"] = ""
    all_df["Variant Inventory Tracker"] = "shopify"
    all_df["Variant Inventory Qty"] = df["Qty"]
    all_df["Variant Inventory Policy"] = "deny"
    all_df["Variant Fulfillment Service"] = "manual"
    all_df["Variant Price"] = df["Price"]
    all_df["Variant Compare At Price"] = ""
    all_df["Variant Requires Shipping"] = ""
    all_df["Variant Taxable"] = ""
    all_df["Variant Barcode"] = ""
    all_df["Image Src"] = df["img"]
    all_df["Image Position"] = ""
    all_df["Image Alt Text"] = ""
    all_df["Gift Card"] = ""
    all_df["SEO Title"] = ""
    all_df["SEO Description"] = ""
    all_df["Google Shopping / Google Product Category"] = ""
    all_df["Google Shopping / Gender"] = ""
    all_df["Google Shopping / Age Group"] = ""
    all_df["Google Shopping / MPN"] = ""
    all_df["Google Shopping / AdWords Grouping"] = ""
    all_df["Google Shopping / AdWords Labels"] = ""
    all_df["Google Shopping / Condition"] = ""
    all_df["Google Shopping / Custom Product"] = ""
    all_df["Google Shopping / Custom Label 0"] = ""
    all_df["Google Shopping / Custom Label 1"] = ""
    all_df["Google Shopping / Custom Label 2"] = ""
    all_df["Google Shopping / Custom Label 3"] = ""
    all_df["Google Shopping / Custom Label 4"] = ""
    all_df["Variant Image"] = ""
    all_df["Variant Weight Unit"] = ""
    all_df["Variant Tax Code"] = ""
    all_df["Cost per item"] = ""
    all_df["Price / International"] = ""
    all_df["Compare At Price / International"] = ""
    all_df["Status"] = "active"

    # replace "&amp;" with "&" in the "Product Category" column
    all_df["Product Category"] = all_df["Product Category"].str.replace("&amp;", "&")

    # save the DataFrame to a CSV file
    all_df.to_csv("products.csv", encoding="utf-8", index=False)

