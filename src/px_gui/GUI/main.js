

// Connecting to ROS
// -----------------
var ros = new ROSLIB.Ros();

// If there is an error on the backend, an 'error' emit will be emitted.
ros.on('error', function (error) {
    document.getElementById('connecting').style.display = 'none';
    document.getElementById('connected').style.display = 'none';
    document.getElementById('closed').style.display = 'none';
    document.getElementById('error').style.display = 'inline';
    console.log(error);
});

// Find out exactly when we made a connection.
ros.on('connection', function () {
    console.log('Connection made!');
    document.getElementById('connecting').style.display = 'none';
    document.getElementById('error').style.display = 'none';
    document.getElementById('closed').style.display = 'none';
    document.getElementById('connected').style.display = 'inline';
});

ros.on('close', function () {
    console.log('Connection closed.');
    document.getElementById('connecting').style.display = 'none';
    document.getElementById('connected').style.display = 'none';
    document.getElementById('closed').style.display = 'inline';
});

// Create a connection to the rosbridge WebSocket server.
ros.connect('ws://localhost:9090');

var gripperStatePublisher = new ROSLIB.Topic({
    ros: ros,
    name: '/gripper',
    messageType: 'std_msgs/Float32'
});


Leap.loop({background: "true"}, function (frame) {
    const element = document.getElementById('handsCounter');


    let data = 0;
    if (frame.hands.length > 0) {
        const hand = frame.hands[0];
        const gs = hand.grabStrength;

        data = gs
        var gripperState = new ROSLIB.Message({
            data: data
        });

        gripperStatePublisher.publish(gripperState);
        // element.innerHTML = 'Force: ' + data;

        const indicators = document.getElementsByClassName('indicator');

        for (indicator of indicators) {
            const _MAX_SIZE = 150;
            let newSize = ((_MAX_SIZE / 0.3) * ((1 - data) + 0.3));

            indicator.style.width = newSize.toString() + "px";
            indicator.style.height = indicator.style.width;
            indicator.style.opacity = 1 - data;
        }


    }


});

