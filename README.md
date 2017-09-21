# sed2017
In order to run simulations you need to first configure the cd++ environment variables by doing 
source ./configure at the cd++ kernel folder

Then run the last codegen here
./build

Compile the atomics code with
src/make 

Finally to run any probabilistic graph simulation 
cd src
bin/cd++ -m../{generated_model}.ma -e../infection.ev
