
# For Triv VS
# Question fonts bigger, ie. 720 * 0.075 = 54
# Menu fonts smaller, ie. 720 * 0.05 = 36

# 480
./gameplay-encoder -s 36 $1.ttf $1_36.gpb
./gameplay-encoder -s 24 $1.ttf $1_24.gpb

# 640
./gameplay-encoder -s 48 $1.ttf $1_48.gpb
./gameplay-encoder -s 32 $1.ttf $1_32.gpb

# 720
./gameplay-encoder -s 54 $1.ttf $1_54.gpb
# ./gameplay-encoder -s 36 $1.ttf $1_36.gpb

# 750
./gameplay-encoder -s 56 $1.ttf $1_56.gpb
./gameplay-encoder -s 37 $1.ttf $1_37.gpb

# 768
./gameplay-encoder -s 57 $1.ttf $1_57.gpb
./gameplay-encoder -s 38 $1.ttf $1_38.gpb

# 1080
./gameplay-encoder -s 81 $1.ttf $1_81.gpb
./gameplay-encoder -s 54 $1.ttf $1_54.gpb

# 1280
./gameplay-encoder -s 96 $1.ttf $1_96.gpb
./gameplay-encoder -s 64 $1.ttf $1_64.gpb

# 1536
./gameplay-encoder -s 115 $1.ttf $1_115.gpb
./gameplay-encoder -s 76 $1.ttf $1_76.gpb

