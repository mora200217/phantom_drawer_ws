function [data, info] = moveRobotRequest
%moveRobot gives an empty data for px_msgs/moveRobotRequest
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/moveRobotRequest';
[data.Config, info.Config] = ros.internal.ros.custommessages.px_msgs.pxConfig;
info.Config.MLdataType = 'struct';
info.MessageType = 'px_msgs/moveRobotRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,6);
info.MatPath{1} = 'config';
info.MatPath{2} = 'config.q1';
info.MatPath{3} = 'config.q2';
info.MatPath{4} = 'config.q3';
info.MatPath{5} = 'config.q4';
info.MatPath{6} = 'config.q5';
