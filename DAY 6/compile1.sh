for f in ex*.c; do
    gcc "$f" -o "${f%.c}"
done
