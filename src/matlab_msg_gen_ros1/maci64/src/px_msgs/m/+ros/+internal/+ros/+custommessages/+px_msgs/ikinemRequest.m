function [data, info] = ikinemRequest
%ikinem gives an empty data for px_msgs/ikinemRequest
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/ikinemRequest';
[data.DesiredPosition, info.DesiredPosition] = ros.internal.ros.messages.geometry_msgs.vector3;
info.DesiredPosition.MLdataType = 'struct';
info.MessageType = 'px_msgs/ikinemRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'desiredPosition';
info.MatPath{2} = 'desiredPosition.x';
info.MatPath{3} = 'desiredPosition.y';
info.MatPath{4} = 'desiredPosition.z';
