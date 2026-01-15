#!/bin/bash

while true
do
    echo "=========================="
    echo " 0 - ----- ONLY NEGATIF"
    echo " 1 - ----- ONLY POSITIF"
    echo " 2 - ------------ MIXTE"
    echo " 3 - -------- SANS FLAG"
    echo " 4 - ------ SIMUL ERROR"
    echo " 5 - ------- TEST BENCH"
    echo " 6 -  TEST BENCH SORTIE"
    echo " 7 - ------- TEST LEN 3"
    echo " 8 - ------- TEST LEN 5"
    echo " 9 - ----- TEST LEN 500"
    echo "10 - ------ CLOSE TEST"
    echo "ENTRER LE TEST QUE TU VEUX FAIRE : "
    read nombre

    case "$nombre" in 
        0)
            echo "ONLY NEGATIF"
            echo "#################################################"
            echo "#################################################"
            echo "========================"
            echo "======TEST SIMPLE N====="
            echo "========================"
            ARG="2147483647 -2147483648 8 9 -35 40 -20 7 5 30  10"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="-147 -71 -59 -194 -86 -14 -49 -32 -137 -113"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="-127 -57 -151 -163 -159 -66 -128 -147 -68 -83"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="-64 -109 -102 -176 -15 -19 -103 -38 -192 -37"; ./push_swap --simple $ARG | ./checker $ARG

            echo "========================"
            echo "======TEST MEDIUM N====="
            echo "========================"
            ARG="2147483647 -2147483648 8 9 -35 40 -20 7 5 30  10"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="-147 -71 -59 -194 -86 -14 -49 -32 -137 -113"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="-127 -57 -151 -163 -159 -66 -128 -147 -68 -83"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="-64 -109 -102 -176 -15 -19 -103 -38 -192 -37"; ./push_swap --medium $ARG | ./checker $ARG

            echo "========================"
            echo "======TEST COMPLEX N===="
            echo "========================"
            ARG="2147483647 -2147483648 8 9 -35 40 -20 7 5 30  10"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="-147 -71 -59 -194 -86 -14 -49 -32 -137 -113"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="-127 -57 -151 -163 -159 -66 -128 -147 -68 -83"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="-64 -109 -102 -176 -15 -19 -103 -38 -192 -37"; ./push_swap --complex $ARG | ./checker $ARG
            ;;
        1)
            echo "#################################################"
            echo "#################################################"
            echo "ONLY POSITIF"
            echo "#################################################"
            echo "#################################################"
            echo "========================"
            echo "======TEST SIMPLE P====="
            echo "========================"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --simple $ARG | ./checker $ARG

            echo "========================"
            echo "======TEST MEDIUM P====="
            echo "========================"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --medium $ARG | ./checker $ARG

            echo "========================"
            echo "======TEST COMPLEX P===="
            echo "========================"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --complex $ARG | ./checker $ARG
            ;;
        2)
            echo "#################################################"
            echo "#################################################"
            echo "MIXTE"
            echo "#################################################"
            echo "#################################################"

            echo "========================"
            echo "======TEST SIMPLE P====="
            echo "========================"
            ARG="0 147 71 -59 194 -86 -14 49 32 137 113"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="127 57 -151 163 -159 0 66 -128 147 68 83"; ./push_swap --simple $ARG | ./checker $ARG
            ARG="64 109 102 176 15 19 -103 38 192 37 0"; ./push_swap --simple $ARG | ./checker $ARG

            echo "========================"
            echo "======TEST MEDIUM P====="
            echo "========================"
            ARG="0 147 71 -59 194 86 14 49 32 137 113"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="127 57 151 -163 0 159 66 128 147 68 83"; ./push_swap --medium $ARG | ./checker $ARG
            ARG="64 109 -102 176 15 19 -103 38 192 37 0"; ./push_swap --medium $ARG | ./checker $ARG

            echo "========================"
            echo "======TEST COMPLEX P===="
            echo "========================"
            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="127 57 151 0 163 159 -66 128 -147 68 83"; ./push_swap --complex $ARG | ./checker $ARG
            ARG="64 -109 102 -176 15 19 -103 38 192 37 0"; ./push_swap --complex $ARG | ./checker $ARG
            ;;
        3)
            echo "#################################################"
            echo "#################################################"
            echo "SANS FLAG"
            echo "#################################################"
            echo "#################################################"

            ARG="0 147 71 -59 194 -86 -14 49 32 137 113"; ./push_swap $ARG | ./checker $ARG
            ARG="127 57 -151 163 -159 0 66 -128 147 68 83"; ./push_swap $ARG | ./checker $ARG
            ARG="64 109 102 176 15 19 -103 38 192 37 0"; ./push_swap $ARG | ./checker $ARG
            ;;
        4)
            echo "#################################################"
            echo "#################################################"
            echo "SIMUL ERROR ON PUSH_SWAP"
            echo "#################################################"
            echo "#################################################"
            echo "DOUBLE FLAG"

            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --complex --complex $ARG
            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --simple --simple $ARG
            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --medium --mediun $ARG
            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --adaptive --adaptive $ARG
            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --bench --bench $ARG
            echo "#################################################"
            echo "SAME TYPE FLAG"

            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --simple --complex $ARG
            echo "#################################################"
            echo "TOO MUCH FLAG"

            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --simple --bench --adaptive $ARG
            echo "#################################################"
            echo "WRONG FLAG"

            ARG="0 147 71 59 -194 86 14 49 32 137 113"; ./push_swap --simple --test --error $ARG
            echo "#################################################"
            echo "DOUBLE NUMBER"

            ARG="0 147 71 59 -194 86 14 49 32 137 0 113"; ./push_swap --simple --test --error $ARG
            echo "#################################################"
            echo "TEST WRONG INPUT ON THE NUMBERS"
            ./push_swap --simple 5 3 4 2 d
            ./push_swap --simple 5 3 c 4 2
            ./push_swap --simple v 5 3 4 2
            ./push_swap --simple 5 3 4 2 455313212345
            ./push_swap --simple 5 3 4 2 "++++432"
            ./push_swap --simple 5 3 4 2 +++--43
            ./push_swap --simple 5 3 4 2 +
            ;;
        5)
            echo "#################################################"
            echo "TEST BENCH"
            echo "#################################################"
            echo "========================"
            echo "======TEST SIMPLE ======"
            echo "========================"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --simple --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --simple --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --simple --bench $ARG 1> test.txt

            echo "========================"
            echo "======TEST MEDIUM ======"
            echo "========================"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --medium --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --medium --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --medium --bench $ARG 1> test.txt

            echo "========================"
            echo "======TEST COMPLEX ====="
            echo "========================"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --complex --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --complex --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --complex --bench $ARG 1> test.txt

            echo "========================"
            echo "======TEST ADAPTIV ====="
            echo "========================"
            echo "#################################################"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --bench $ARG 1> test.txt
            echo "#################################################"
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --bench $ARG 1> test.txt
            echo "#################################################"
            rm test.txt
            ;;
        6)
            echo "#################################################"
            echo "TEST BENCH SI SORTIE 2"
            echo "#################################################"
            ARG="147 71 59 194 86 14 49 32 137 113"; ./push_swap --bench $ARG > test.txt 2> bench.txt
            echo "CAT BENCH bench.txt"
            cat bench.txt
            ARG="127 57 151 163 159 66 128 147 68 83"; ./push_swap --bench $ARG > test.txt 2> bench.txt
            echo "CAT BENCH bench.txt"
            cat bench.txt
            ARG="64 109 102 176 15 19 103 38 192 37"; ./push_swap --bench $ARG > test.txt 2> bench.txt
            echo "CAT BENCH bench.txt"
            cat bench.txt
            rm bench.txt
            rm test.txt
            ;;
        7)
            echo "TEST LEN 3"
            echo "#################################################"
            echo "#################################################"
            echo "========================"
            echo "======TEST SIMPLE ======"
            echo "========================"
            ARG="2 0 1"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1"; ./push_swap --simple $ARG | wc -l
            echo "##################"
            ARG="0 4 2"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2"; ./push_swap --simple $ARG | wc -l
            echo "##################"
            ARG="27 5 -2"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2"; ./push_swap --simple $ARG | wc -l
            echo "##################"
            ARG="17 20 0"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0"; ./push_swap --simple $ARG | wc -l

            echo "========================"
            echo "======TEST MEDIUM ======"
            echo "========================"
            ARG="2 0 1"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1"; ./push_swap --medium $ARG | wc -l
            echo "##################"
            ARG="0 4 2"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2"; ./push_swap --medium $ARG | wc -l
            echo "##################"
            ARG="27 5 -2"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2"; ./push_swap --medium $ARG | wc -l
            echo "##################"
            ARG="17 20 0"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0"; ./push_swap --medium $ARG | wc -l

            echo "========================"
            echo "======TEST COMPLEX ====="
            echo "========================"
            ARG="2 0 1"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1"; ./push_swap --complex $ARG | wc -l
            echo "##################"
            ARG="0 4 2"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2"; ./push_swap --complex $ARG | wc -l
            echo "##################"
            ARG="27 5 -2"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2"; ./push_swap --complex $ARG | wc -l
            echo "##################"
            ARG="17 20 0"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0"; ./push_swap --complex $ARG | wc -l

            echo "========================"
            echo "======TEST ADAPTIV ====="
            echo "========================"
            ARG="2 0 1"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1"; ./push_swap $ARG | wc -l
            echo "##################"
            ARG="0 4 2"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2"; ./push_swap $ARG | wc -l
            echo "##################"
            ARG="27 5 -2"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2"; ./push_swap $ARG | wc -l
            echo "##################"
            ARG="17 20 0"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0"; ./push_swap $ARG | wc -l
            ;;
        8)
            echo "TEST LEN 5"
            echo "#################################################"
            echo "#################################################"
            echo "========================"
            echo "======TEST SIMPLE ======"
            echo "========================"
            ARG="2 0 1 5 20"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1 5 20"; ./push_swap --simple $ARG | wc -l
            echo "##################"
            ARG="0 4 2 -100 7"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2 -100 7"; ./push_swap --simple $ARG | wc -l
            echo "##################"
            ARG="27 5 -2 10 3"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2 10 3"; ./push_swap --simple $ARG | wc -l
            echo "##################"
            ARG="17 20 0 -400 -245"; ./push_swap --simple $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0 -400 -245"; ./push_swap --simple $ARG | wc -l

            echo "========================"
            echo "======TEST MEDIUM ======"
            echo "========================"
            ARG="2 0 1 5 20"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1 5 20"; ./push_swap --medium $ARG | wc -l
            echo "##################"
            ARG="0 4 2 -100 7"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2 -100 7"; ./push_swap --medium $ARG | wc -l
            echo "##################"
            ARG="27 5 -2 10 3"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2 10 3"; ./push_swap --medium $ARG | wc -l
            echo "##################"
            ARG="17 20 0 -400 -245"; ./push_swap --medium $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0 -400 -245"; ./push_swap --medium $ARG | wc -l

            echo "========================"
            echo "======TEST COMPLEX ====="
            echo "========================"
            ARG="2 0 1 5 20"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1 5 20"; ./push_swap --complex $ARG | wc -l
            echo "##################"
            ARG="0 4 2 -100 7"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2 -100 7"; ./push_swap --complex $ARG | wc -l
            echo "##################"
            ARG="27 5 -2 10 3"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2 10 3"; ./push_swap --complex $ARG | wc -l
            echo "##################"
            ARG="17 20 0 -400 -245"; ./push_swap --complex $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0 -400 -245"; ./push_swap --complex $ARG | wc -l

            echo "========================"
            echo "======TEST ADAPTIV ====="
            echo "========================"
            ARG="2 0 1 5 20"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="2 0 1 5 20"; ./push_swap $ARG | wc -l
            echo "##################"
            ARG="0 4 2 -100 7"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="0 4 2 -100 7"; ./push_swap $ARG | wc -l
            echo "##################"
            ARG="27 5 -2 10 3"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="27 5 -2 10 3"; ./push_swap $ARG | wc -l
            echo "##################"
            ARG="17 20 0 -400 -245"; ./push_swap $ARG | ./checker $ARG
            echo -n "MOUVEMENT :"
            ARG="17 20 0 -400 -245"; ./push_swap $ARG | wc -l
            ;;
        9)
            echo "TEST LEN 500"
            echo "#################################################"
            echo "#################################################"

            echo "========================"
            echo "======TEST ADAPTIV ====="
            echo "========================"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            echo "##################"
            shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)
            echo -n "MOUVEMENT :"
            ./push_swap $(cat args.txt) | wc -l
            rm args.txt
            ;;
        10)
            echo "Au revoir"
            exit 0
            ;;
    esac
    echo "==============================="
    echo "TAPE NIMPORTE POUR GO NEXT : "
    read tape
    clear
done