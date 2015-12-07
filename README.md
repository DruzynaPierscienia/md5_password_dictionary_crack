## md5 password cracking program

### Install libraries:
```
sudo apt-get install libssl-dev cmake 
```

#### Install gtest:
```
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip gtest-1.7.0.zip
cd gtest-1.7.0/
./configure
make
sudo cp -a include/gtest /usr/include
sudo cp -a lib/.libs/* /usr/lib/
```

### Compilation and run
```
mkdir build
cd build
cmake ..
make
```