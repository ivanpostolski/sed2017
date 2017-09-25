# SED2017 TP1:Modelado y simulación para un sistema controlado de dinámica SIR con Vacunación en un entorno de grafo estocástico.

Autores: Ferreyra Emanuel, Martin Rafael, Postolski Ivan

### In order to run simulations you need to first configure the cd++ environment variables by doing 


*source ./configure* 

At the cdpp kernel folder

### Then to build the last atomic generation


*./build*


### The following step is compile the atomics code with cdpp library by doing


*src/make* 


### In order to run a simulation on any of the provided graph models (already generated under models/) folder

*cd src*

*bin/cd++ -m../models/{any_model}.ma -e../infection.ev*


### To build a new graph model, use the python *graphgen.py* like the following 


*python graphgen.py {n} {alpha,defaults to 10}*


### Finally to reproduce the experiments 

*cd experiments_logs/*
*./run_experiments*

### And sanity testing over the experiments

*./run_sanity_tests_on_experiments*

### *Additional* In order to create a plot for an individual log file

cd experiments_logs/
python graficos.py {logfile}


### *Additional* In order to run any of the unit tests, go to unit_tests folder and see the Readme.txt file

