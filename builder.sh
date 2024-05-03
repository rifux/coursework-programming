#   Environmental variables
ENV_RUN=0
ENV_ERASE=0
BINARY_NAME="bin"


#   Deleting cached files
function clean() {
    for name in {"CMakeFiles","CMakeCache.txt","cmake_install.cmake","Makefile",$BINARY_NAME}; do
        if [ -e $name ]; then
            rm -r $name
        fi
    done
}


#   Reading args
for arg in $*; do case $arg in
    c | clean )
        clean
        clear
        ;;
    ce | clean-exit )
        clean
        clear
        exit
        ;;
    r | run )
        ENV_RUN=1
        ;;
    or | oneshot-run )
        ENV_RUN=1
        ENV_ERASE=1
        ;;
esac; shift; done


#   Building 
cmake . && cmake --build . && chmod +x $BINARY_NAME


#   Run binary if required
if [[ $ENV_RUN -eq 1 ]]; then
    echo -e "\n$BINARY_NAME:"
    exec ./$BINARY_NAME
fi


#   Clean after ewxecuting binary if required
if [[ $ENV_ERASE -eq 1 ]]; then
    clean
fi