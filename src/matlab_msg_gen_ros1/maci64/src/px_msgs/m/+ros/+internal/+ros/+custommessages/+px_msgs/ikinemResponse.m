function [data, info] = ikinemResponse
%ikinem gives an empty data for px_msgs/ikinemResponse
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/ikinemResponse';
[data.RobotConfiguration, info.RobotConfiguration] = ros.internal.ros.custommessages.px_msgs.pxConfigVector;
info.RobotConfiguration.MLdataType = 'struct';
info.MessageType = 'px_msgs/ikinemResponse';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,5);
info.MatPath{1} = 'robotConfiguration';
info.MatPath{2} = 'robotConfiguration.q1';
info.MatPath{3} = 'robotConfiguration.q2';
info.MatPath{4} = 'robotConfiguration.q3';
info.MatPath{5} = 'robotConfiguration.q4';
