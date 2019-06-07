set terminal gif size 1024,768 animate delay 4
set output '1D_Waves.gif'
set xrange [0:1]
set yrange [-0.12:0.12]
set key Left
plot "data_0.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0" with lines
plot "data_1.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0.15708" with lines
plot "data_2.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0.314159" with lines
plot "data_3.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0.471239" with lines
plot "data_4.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0.628319" with lines
plot "data_5.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0.785398" with lines
plot "data_6.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=0.942478" with lines
plot "data_7.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=1.09956" with lines
plot "data_8.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=1.25664" with lines
plot "data_9.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=1.41372" with lines
plot "data_10.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=1.5708" with lines
plot "data_11.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=1.72788" with lines
plot "data_12.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=1.88496" with lines
plot "data_13.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.04204" with lines
plot "data_14.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.19911" with lines
plot "data_15.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.35619" with lines
plot "data_16.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.51327" with lines
plot "data_17.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.67035" with lines
plot "data_18.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.82743" with lines
plot "data_19.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=2.98451" with lines
plot "data_20.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=3.14159" with lines
plot "data_21.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=3.29867" with lines
plot "data_22.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=3.45575" with lines
plot "data_23.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=3.61283" with lines
plot "data_24.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=3.76991" with lines
plot "data_25.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=3.92699" with lines
plot "data_26.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=4.08407" with lines
plot "data_27.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=4.24115" with lines
plot "data_28.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=4.39823" with lines
plot "data_29.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=4.55531" with lines
plot "data_30.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=4.71239" with lines
plot "data_31.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=4.86947" with lines
plot "data_32.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.02655" with lines
plot "data_33.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.18363" with lines
plot "data_34.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.34071" with lines
plot "data_35.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.49779" with lines
plot "data_36.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.65487" with lines
plot "data_37.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.81195" with lines
plot "data_38.txt" title "I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\n C = 1\n gamma = 0.31831\n t=5.96903" with lines
