from flask import Flask, request, render_template
from db import init_db

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    result = ""

    if request.method == 'POST':
        realname = request.form.get('realname')

        conn = init_db()
        c = conn.cursor()

        query = f"SELECT * FROM users WHERE username = 'admin' AND realname = '{realname}'"

        try:
            c.execute(query)
            user = c.fetchone()

            if user:
                result = "Congratulations! Here's your flag: brAInwave{d0n7_be_4fr41d_0f_1njec710n5}"
            else:
                result = "Access Denied"
        except Exception as e:
            result = f"Database error: {e}"

        conn.close()

    return render_template('index.html', result=result)

if __name__ == '__main__':
    app.run(debug=True, host="0.0.0.0", port=5000)
