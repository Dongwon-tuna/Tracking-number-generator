# Tracking Number Generator / 택배 운송장번호 생성기


During the winter vacation I worked in Coupang Cheonan HUB. Through the above experience I'm interested about transportation business. So i decided to make my own transportation system. Tracking Nuber Generator is first step of my transportation system.

겨울방학동안 쿠팡 천안 허브에서 일을 했고 이를 통하여 운송 사업에 관하여 관심이 생겼다. 그래서 나만의 운송 시스템을 구축해보고 싶다는 생각이 들었고, 택배 운송장번호 생성기는 그 프로젝의 첫 걸음이다.

## Explanation about Tracking Number Generator / 택배 운송장번호 생성기에 관한 설명

### 1. Based on South Korea zipcode system / 대한민국의 우편번호를 기반으로 한 배송 시스템


![11](https://github.com/Dongwon-tuna/Tracking-number-generator/assets/61178312/fcbf697b-8e42-4629-9bca-58eed7752c47)


Korean address is based on the road. For example, my house is next to Bongjeong road. At this road, there are 400 houses and my house is 365th. According to this system, my address is "365, Bonjeong-ro"(-ro means road). When the delivery system is activated on this kind of address, there are some kinds of problems. First, It might cause traffic jams because of delivery trucks. Second, many of residential spaces are aprtment. Korean address is based on road, so using the address information only for delivery is inefficient. As you can see pictures above, that kind of distriction is much more efficient in delivery system. That kind of districtios are based on Korean zipcode. This is the reason why The "Tracking Number Generator" is based on Korea zipcode system.


### 2. Making unique tracking number / 중복되지 않는 유일한 운송장번호를 만드는 법 
Through the Korean zipcode based distriction, there are almost 10,000 pepoles lived in my distriction. Through the population density and my assumption, the maximum population of one distriction might be 20,000. On average there are 100 parcel out of 1000 people. This statistic is based on my Coupang HUB experience and my colleague's. To avoid making same tracking number, there might be 2000 different codes required. So I bring 3 charcter from user's id(first,middle,last one) and changed in hexademical numbers in ASCII. Also using the time stamp of payment record.

**Order information**![주문정보](https://github.com/Dongwon-tuna/Tracking-number-generator/assets/61178312/aa7ed693-42aa-480c-b822-62b689420468)

**Tracking number**

![번호수정](https://github.com/Dongwon-tuna/Tracking-number-generator/assets/61178312/e9b7901d-9aa7-4bd4-9503-459d0b03e6e9)

**1.** First red box(**344**) is the number using the time stamp of payment record. This information is kind of privacy, so I tried to encrypt this information. I used XOR(eXclusive OR) for encryption. If you didn't know about XOR or XOR encryption, please refer to the picture below.

![암호화](https://github.com/Dongwon-tuna/Tracking-number-generator/assets/61178312/65275d37-936d-4611-a7bd-741bc5b2a7c3)

I'm gonna use 2024_03_13_08_28_36(YYYY_MM_DD_HH_MM_SS) for example. First 08_28(HH_MM) is changed in to int 823, and changed in to 12 binary nuber as 001100111100. XOR encryption needs a key value, so i use 36(SS) as key value. 36 in binary is 100100. We need 12 binary number. So I flipped this 6 binary number and add to the original. 001001100100 is made and this is the key value. Using 001100111100 and key value 001001100100 for XOR encryption, 000101011000 is our new ciphertext. And then convert this binary to decimal, the First Red Box number **"344"** is generated.

**2.** Second red box(**13**) is date.

**3.** Third red box(**666d32**) is the 3 charcter from user's id(first,middle,last one) and changed in hexademical numbers in ASCII. If the length of the char is even, the middle value is 
arr[length/2]. According to the order information, ID is fkfxcmvn12, we choose "f" , "m" , "2" and these are converted int to "66" , "6d" , "32". 

**4.** Fourth red box(**1257**) is information about korea administrative district. In this project, I only made tracking number about my hometown(365, Bongjeong-ro, Seobuk-gu, Cheonan-si, Chungcheongnam-do, Republic of Korea). **12** is the code of "Chungcheongnam-do". **57** is the code of "Dongman-gu, Cheonan-si". If some number is **1256**, **56** is "Seobuk-gu, Cheonan-si"

The green area is "Seobuk-gu, Cheonan-si", gray area is "Dongman-gu, Cheonan-si". 

![서북구](https://github.com/Dongwon-tuna/Tracking-number-generator/assets/61178312/ae6d42ca-9d1f-4ae2-9ac3-f3436b42efda)

**5.** Fifth red box(**31102**) is zipcode number.


### 3. Waybill Standardization / 운송장 표준화

