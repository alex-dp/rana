for i in `basename -s ".rn" tests/*.rn`; do
    echo $i":"
    ./rana tests/"$i".rn
    diff tests/"$i".html tests/"$i".expected && echo "(passed)" || true
done
