function [data, info] = pxConfigVector
%pxConfigVector gives an empty data for px_msgs/pxConfigVector
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/pxConfigVector';
[data.Q1, info.Q1] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Q2, info.Q2] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Q3, info.Q3] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Q4, info.Q4] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'px_msgs/pxConfigVector';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'q1';
info.MatPath{2} = 'q2';
info.MatPath{3} = 'q3';
info.MatPath{4} = 'q4';
