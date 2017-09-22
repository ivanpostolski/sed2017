[top] //this represent the a <-> b <-> c graph, where a is initially infected
components : a@persona1 b@persona2 c@persona1 
in : infect
link : infect infect@a
link : out0@a in0@b
link : out0@b in0@a
link : out0@c in1@b
link : out1@b in0@c