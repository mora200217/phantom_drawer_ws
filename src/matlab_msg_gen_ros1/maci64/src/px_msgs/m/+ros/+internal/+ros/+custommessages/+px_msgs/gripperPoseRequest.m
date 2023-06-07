function [data, info] = gripperPoseRequest
%gripperPose gives an empty data for px_msgs/gripperPoseRequest
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/gripperPoseRequest';
[data.DesiredGripperPose, info.DesiredGripperPose] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'px_msgs/gripperPoseRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'desiredGripperPose';
