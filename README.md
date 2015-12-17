## md5 password cracking program

Project [Roadmap](https://trello.com/b/90Fdom47/md5passwrodcracker) in trello organizer.

### Install libraries:
```bash
sudo apt-get install libssl-dev cmake 
```

#### Install gtest:
```bash
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip gtest-1.7.0.zip
cd gtest-1.7.0/
./configure
make
sudo cp -a include/gtest /usr/include
sudo cp -a lib/.libs/* /usr/lib/
```
#### Install gmock:
```bash
wget https://googlemock.googlecode.com/files/gmock-1.7.0.zip
unzip gmock-1.7.0.zip 
cd gmock-1.7.0/
./configure
make
sudo cp -a include/gmock /usr/include
sudo cp -a lib/.libs/* /usr/lib/
```

### Compilation and run
```bash
mkdir build
cd build
cmake ..
make
```

### Running tests
```bash
./runUnitTests
```
