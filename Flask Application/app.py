from flask import Flask, render_template, request
import subprocess

app = Flask(__name__)
PLUGIN_DIR = 'Plugins\\'

@app.route('/')
def index():
    messages = [{'title': 'Praetorian', 'content': 'Hasher Test Application'}]
    return render_template('index.html', messages=messages)

@app.route('/hash', methods=('GET', 'POST'))
def hash():
    hashes = []
    if request.method == 'POST':
        cmd = [
                PLUGIN_DIR + 'Worker.exe',
                request.form['engine'],
                request.form['method'],
                request.form['id'],
                request.form['title'],
                request.form['content'],
                request.form['operation'],
                request.form['mode']
        ]

        output = subprocess.run(cmd, stdout=subprocess.PIPE)
        returnVals = output.stdout.decode("utf-8").split('\r\n')
        if len(returnVals) < 2:
            returnVals = ['ERROR', 'ERROR']

        hashes=[{'clear': returnVals[0], 'hashed': returnVals[1]}]
    return render_template('hash.html', hashes=hashes)

app.run(host='0.0.0.0', port=80)