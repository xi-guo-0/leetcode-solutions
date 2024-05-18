cat words.txt | awk '{for(i=1;i<=NF;i++) num[$i]++;} END{ for(k in num) print k" "num[k]}' | sort -rnk 2
