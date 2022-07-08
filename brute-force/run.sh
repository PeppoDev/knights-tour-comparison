
function runner(){
    for i in {1..5}; do 
       $1
    done
}


# test n = 6 origin 0,0
echo "Starting test n = 6  origin 0,0"
sed -i '9d;10d' backtracking.cpp 
sed -i '9s/^/int const N = 6; \n /' backtracking.cpp 
sed -i '10s/^/int const origin[2] = {0, 0}; \n/' backtracking.cpp 
g++ -o output ./backtracking.cpp
runner "timeout 5h bash -c ./output" >> result.txt

# # test n = 8 origin 0,0
echo "Starting test n = 8  origin 0,0"
sed -i '9d;10d' backtracking.cpp 
sed -i '9s/^/int const N = 8; \n /' backtracking.cpp 
sed -i '10s/^/int const origin[2] = {0, 0}; \n/' backtracking.cpp 
g++ -o output ./backtracking.cpp
runner "timeout 5h bash -c ./output" >> result.txt

# test n = 10 origin 0,0
echo "Starting test n = 10 origin 0,0"
sed -i '9d;10d' backtracking.cpp 
sed -i '9s/^/int const N = 10; \n /' backtracking.cpp 
sed -i '10s/^/int const origin[2] = {0, 0}; \n/' backtracking.cpp 
g++ -o output ./backtracking.cpp
runner "timeout 5h bash -c ./output" >> result.txt



