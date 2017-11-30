# algorithm_study4

쌓아 올리기(Stack 'em Up)

52장의 카드를 주어진 방법에 따라 섞는데, 어떻게 섞였는지 출력하라는 것이다. 카드를 섞는 방법은 일명 "밑장 빼기"의 응용버전 인, "원하는 부분의 카드를 빼서 위에 쌓아 올리기" 이다. 즉, 카드의 아래서 위로 순번으로 매길때, 3번의 카드를 빼서 52번째 카드의 자리에 카드를 올려 놓는 섞기 방법이다.
여기서 중요한 점은, 실시간으로 카드 섞임을 누적하지 않고, 섞는 방법들 중 한 가지 방법으로 섞고 난 후에야 비로서 누적한다. 즉, "1번째 카드를 3번째 자리에 넣으라고 했을때, 2번째 자리가 1번째에 오지 않는다. 하지만 이런식으로 섞은 후에 카드 섞임 상태는 유지 한다." 를 뜻한다.

input
1. 테스트 케이스의 갯수를 정수로 입력 받는다.
2. 공백라인을 넣는다.
3. 섞는 방법의 갯수를 정수(100 이하)로 입력 받는다. 
4. 섞는 방법의 갯수 만큼 섞는 방법을 입력 받는다. 이때 1 부터 52개의 숫자 중 중복되지 않게 52개를 입력 받는다.
5. 첫번째 입력이 첫번째 위치에 있을 카드 입력이다.
6. 섞는 방법의 갯수 만큼 입력 받았다면, 섞는 방법을 입력받은 순으로 아이디(정수)화 하여, 섞는 방법을 입력 받는다. 
7. 섞는 방법을 입력받으면, 섞고, 0이 입력 될때까지 반복한다.

output
1. 입력의 7번째에서 공백이 입력 되었다면, 지금까지 누적시킨 카드를 출력한다.
2. 공백을 출력한다.
3. 테스트 케이스 만큼 입력을 받으며 출력을 반복한다.

input example
- 1
- 
- 2
- 2 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 52 51
- 52 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 1
- 1
- 2

output example
- King of Spades
- 2 of Clubs
- 4 of Clubs
- 5 of Clubs
- 6 of Clubs
- 7 of Clubs
- 8 of Clubs
- 9 of Clubs
- 10 of Clubs
- Jack of Clubs
- Queen of Clubs
- King of Clubs
- Ace of Clubs
- 2 of Diamonds
- 3 of Diamonds
- 4 of Diamonds
- 5 of Diamonds
- 6 of Diamonds
- 7 of Diamonds
- 8 of Diamonds
- 9 of Diamonds
- 10 of Diamonds
- Jack of Diamonds
- Queen of Diamonds
- King of Diamonds
- Ace of Diamonds
- 2 of Hearts
- 3 of Hearts
- 4 of Hearts
- 5 of Hearts
- 6 of Hearts
- 7 of Hearts
- 8 of Hearts
- 9 of Hearts
- 10 of Hearts
- Jack of Hearts
- Queen of Hearts
- King of Hearts
- Ace of Hearts
- 2 of Spades
- 3 of Spades
- 4 of Spades
- 5 of Spades
- 6 of Spades
- 7 of Spades
- 8 of Spades
- 9 of Spades
- 10 of Spades
- Jace of Spades
- Queen of Spades
- Ace of Spades
- 3 of Clubs
