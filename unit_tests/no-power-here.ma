[top] //this represent the a <-> b <-> c graph, where b is vaccinated and then nodes a and b are infected
components : a@persona1 b@persona3 c@persona1 
in : infect sick
link : sick in2@b
link : infect infect@a
link : infect infect@c
link : out0@a in0@b
link : out0@b in0@a
link : out0@c in1@b
link : out1@b in0@c