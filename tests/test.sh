for i in `basename -s ".rana" tests/*.rana`; do
    echo $i":"
    ./rana tests/"$i".rana
    diff tests/"$i".html tests/"$i".expected && echo "(passed)" || true
done
