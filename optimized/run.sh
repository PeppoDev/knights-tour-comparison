

function runner(){
    for i in {1..5}; do 
       $1
    done
}

# test n = 6  origin 0,0
sed -i '9d;10d' optimized.cpp 
sed -i '9s/^/int const N = 6; \n /' optimized.cpp 
sed -i '10s/^/int const origin[2] = {0, 0}; \n/' optimized.cpp 
g++ -o output ./optimized.cpp
runner "timeout 5h bash -c ./output" >> result.txt


# # test n = 8  origin 0,0
sed -i '9d;10d' optimized.cpp 
sed -i '9s/^/int const N = 8; \n /' optimized.cpp 
sed -i '10s/^/int const origin[2] = {0, 0}; \n/' optimized.cpp 
g++ -o output ./optimized.cpp
runner "timeout 5h bash -c ./output" >> result.txt


# # test n = 10  origin 0,0
sed -i '9d;10d' optimized.cpp 
sed -i '9s/^/int const N = 10; \n /' optimized.cpp 
sed -i '10s/^/int const origin[2] = {0, 0}; \n/' optimized.cpp 
g++ -o output ./optimized.cpp
runner "timeout 5h bash -c ./output" >> result.txt




