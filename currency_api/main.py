from flask import Flask, render_template, request, jsonify
import os
from get_currency import get_currency

template_dir = os.path.join("./templates")

app = Flask(__name__, template_folder=template_dir)


@app.route("/", methods=["GET", "POST"])
def get_data():
    if request.method == "GET":
        return render_template("index.html")
    else:
        from_ = request.form.get("from")
        print(from_)
        to = request.form.get("to")
        print(to)
        value = get_currency(from_, to)
        print(value)
        return jsonify(value=value)


if __name__ == "__main__":
    app.run(debug=True)
