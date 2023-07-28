# Python 3 server example
from http.server import BaseHTTPRequestHandler, HTTPServer
import time, rospy
import webbrowser
import os.path
import logging
from flask import Flask, Response, render_template, send_from_directory


app = Flask(__name__, static_folder='/Users/amoralesma/Documents/UN/robotica/labs/phantom_drawer/src/px_gui/GUI',
            template_folder='/Users/amoralesma/Documents/UN/robotica/labs/phantom_drawer/src/px_gui/GUI')
log = logging.getLogger('werkzeug')
log.disabled = True
# app.config.from_object(__name__)

@app.route('/', methods=['GET'])
def main(): 
    # content = get_file('../GUI/index.html')
    return render_template('index.html')

@app.route('/<path:filename>')
def serve_static(filename):
    root_dir = app.static_folder
    return send_from_directory(root_dir, filename)

if __name__ == "__main__":        
    try:
        webbrowser.open_new('http://127.0.0.1:8000/')
        app.run(port=8000)
    except KeyboardInterrupt or rospy.ROSInterruptException:
        pass

    
    print("Server stopped.")