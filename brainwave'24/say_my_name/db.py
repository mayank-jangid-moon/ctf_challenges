import sqlite3

def init_db():
    conn = sqlite3.connect(':memory:')
    c = conn.cursor()

    c.execute('''
        CREATE TABLE users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL,
            realname TEXT NOT NULL
        )
    ''')

    c.execute("INSERT INTO users (username, realname) VALUES ('admin', 'AdminRealName')")
    c.execute("INSERT INTO users (username, realname) VALUES ('user1', 'John Doe')")
    c.execute("INSERT INTO users (username, realname) VALUES ('user2', 'Jane Smith')")

    conn.commit()
    return conn
