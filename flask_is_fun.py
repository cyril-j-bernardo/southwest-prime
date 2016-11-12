from flask import Flask
app = Flask(__appname__)

@app.route("/")
def hello():
	return "Hello World!"

if __appname__ == "__main__":
	app.run()