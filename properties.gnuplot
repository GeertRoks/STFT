# png
set terminal pngcairo size 1500,700 enhanced font 'Verdana,10'
set output 'flute-c4.png'

set title "Plot name/description - Author, year"

set border linewidth 1.5
# Set first two line styles to blue (#0060ad) and red (#dd181f)
set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 0 linewidth 2 \
    pointtype -1
set style line 2 \
    linecolor rgb '#ff0000' \
    linetype 1 linewidth 2 \
    pointtype -1
set style line 3 \
    linecolor rgb '#3cef39' \
    linetype 1 linewidth 2 \
    pointtype -1

set  xlabel "Samples"
set ytics 1
set tics scale 0.75

set xrange [0:512]
set yrange [-1.5:1.5]
set y2range [-10:10]
set grid
set key
plot 'flute-c4.dat' index 0 using 1:2 with lines title columnheader(1), \
     'flute-c4.dat' index 1 using 1:2 with lines title columnheader(1) axes x1y2
unset key
unset grid
