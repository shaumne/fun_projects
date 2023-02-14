from flask import Flask, render_template, request
import os
from data import get_data

template_dir = os.path.join("./templates")
app = Flask(__name__, template_folder=template_dir)


@app.route("/", methods=["GET", "POST"])
def showData():
    if request.method == "GET":
        return render_template("index.html")
    else:
        city = request.form.get("city")
        data = get_data(city, "2fc420da7511031e19ed2ecd548399e5")
        html_table = data.replace('<table border="1" class="dataframe">',
                                  '<table class="table table-striped \
                                    table-bordered table-hover \
                                    table-sm table-responsive">')
        return render_template("index.html", table=html_table)


if __name__ == "__main__":
    app.run(debug=True)
