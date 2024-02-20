# Tracking Number Generator / 택배 운송장번호 생성기


During the winter vacation I worked in Coupang Cheonan HUB. Through the above experience I'm interested about transportation business. So i decided to make my own transportation system. Tracking Nuber Generator is first step of my transportation system.

겨울방학동안 쿠팡 천안 허브에서 일을 했고 이를 통하여 운송 사업에 관하여 관심이 생겼다. 그래서 나만의 운송 시스템을 구축해보고 싶다는 생각이 들었고, 택배 운송장번호 생성기는 그 프로젝의 첫 걸음이다.

## Explanation about Tracking Number Generator / 택배 운송장번호 생성기에 관한 설명

### 1. Based on South Korea zipcode system / 대한민국의 우편번호를 기반으로 한 배송 시스템


![11](https://github.com/Dongwon-tuna/Tracking-number-generator/assets/61178312/fcbf697b-8e42-4629-9bca-58eed7752c47)


Korean address is based on the road. For example, my house is next to Bongjeong road. At this road, there are 400 houses and my house is 365th. According to this system, my address is "365, Bonjeong-ro"(-ro means road). When the delivery system is activated on this kind of address, there are some kinds of problems. First, It might cause traffic jams because of delivery trucks. Second, many of residential spaces are aprtment. Korean address is based on road, so using the address information only for delivery is inefficient. As you can see pictures above, that kind of distriction is much more efficient in delivery system. That kind of districtios are based on Korean zipcode. This is the reason why The "Tracking Number Generator" is based on Korea zipcode system.


### 2. Making unique tracking number / 중복되지 않는 유일한 운송장번호를 만드는 법 
Through the Korean zipcode basaed distriction, there are almost 10,000 pepoles lived in my distriction. Through the population density and my assumption, the maximum population of one distriction might be 20,000. On average there are 100 parcel out of 1000 people. This statistic is based on my Coupang HUB experience and my colleague's. To avoid making same tracking number, there might be 2000 different codes required.

## Getting Started / 어떻게 시작하나요?



Do this works in order at the terminal. / 다음 순서에 따라서 터미널에서 프로그램을 실행시켜 주세요.

```
gcc -c binary_operations.c -o binary_operations.o
```

```
gcc -c parson.c -o parson.o
```

```
gcc -c main.c -o main.o
```

```
gcc -o generator main.o binary_operations.o parson.o
```

```
./generator
```

### Installing / 설치

아래 사항들로 현 프로젝트에 관한 모듈들을 설치할 수 있습니다.

```
예시
```

## Running the tests / 테스트의 실행

어떻게 테스트가 이 시스템에서 돌아가는지에 대한 설명을 합니다

### 테스트는 이런 식으로 동작합니다

왜 이렇게 동작하는지, 설명합니다

```
예시
```

### 테스트는 이런 식으로 작성하시면 됩니다

```
예시
```

## Deployment / 배포

Add additional notes about how to deploy this on a live system / 라이브 시스템을 배포하는 방법

## Built With / 누구랑 만들었나요?

* [이름](링크) - 무엇 무엇을 했어요
* [Name](Link) - Create README.md

## Contributiong / 기여

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us. / [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) 를 읽고 이에 맞추어 pull request 를 해주세요.

## License / 라이센스

This project is licensed under the MIT License - see the [LICENSE.md](https://gist.github.com/PurpleBooth/LICENSE.md) file for details / 이 프로젝트는 MIT 라이센스로 라이센스가 부여되어 있습니다. 자세한 내용은 LICENSE.md 파일을 참고하세요.

## Acknowledgments / 감사의 말

* Hat tip to anyone whose code was used / 코드를 사용한 모든 사용자들에게 팁
* Inspiration / 영감
* etc / 기타

* 
gcc -c binary_operations.c -o binary_operations.o

gcc -c parson.c -o parson.o

gcc -c main.c -o main.o

gcc -o generator main.o binary_operations.o parson.o

./ generator



