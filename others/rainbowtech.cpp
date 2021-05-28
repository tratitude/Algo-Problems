#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

/*
std::string f()
{
    return static_cast<std::string>("hello world");    // C++ type conversion
operator
//  return std::string("hello world");                 // function-style casting
//  return (std::string)"hello world";                 // C-style casting
//  return "hello world";                              // implicit conversion
//  using namespace std::string_literals;              // string literal
//  return "hello world"s;
}
*/
/*
void quick_sort(std::vector<int>& input, int start, int end)
{
    if(start >= end)
        return;

    int left = start, right = end;
    while(left != right){
        while(left < right && input[left] < input[start]) {++left;}
        while(left < right && input[right] >= input[start]) {--right;}
        std::swap(input[left], input[right]);
    }
    std::swap(input[start], input[left]);

    quick_sort(input, start, left-1);
    quick_sort(input, left+1, end);
}
std::string f(const std::vector<int>& input)
{
    auto vec = std::vector<int>(input);
    quick_sort(vec, 0, vec.size()-1);

    std::string output;
    for(int i=0; i<vec.size(); ++i){
        output.append(std::to_string(vec[i]));
        if(i+1 != vec.size())
            output.append(" ");
    }
    return output;
}
*/
/*
请完成函数f，输入的5个数字代表5张牌，含义如下：
0x102,0x103,0x104,0x105,0x106,0x107,0x108,0x109,0x10a,0x10b,0x10c,0x10d,0x10e分别代表方块2,3,4,5,6,7,8,9,10,J,Q,K,A
0x202,0x203,0x204,0x205,0x206,0x207,0x208,0x209,0x20a,0x20b,0x20c,0x20d,0x20e分别代表梅花2,3,4,5,6,7,8,9,10,J,Q,K,A
0x302,0x303,0x304,0x305,0x306,0x307,0x308,0x309,0x30a,0x30b,0x30c,0x30d,0x30e分别代表红桃2,3,4,5,6,7,8,9,10,J,Q,K,A
0x402,0x403,0x404,0x405,0x406,0x407,0x408,0x409,0x40a,0x40b,0x40c,0x40d,0x40e分别代表黑桃2,3,4,5,6,7,8,9,10,J,Q,K,A
0x50f代表小王
0x610代表大王
小王大王可以变为任意牌，要求算出小王大王变换后最大牌型
返回的数字含义如下：
1、皇家同花顺：如果花色一样，数字分别是10,J,Q,K,A
2、同花顺：如果花色一样，数字是连续的，皇家同花顺除外，例如[0x109,0x10a,0x10b,0x10c,0x10d],[0x10e,0x102,0x103,0x104,0x105]
3、金刚：其中4张牌数字一样
4、葫芦：其中3张牌数字一样，另外2张牌数字一样
5、同花：花色一样，数字不连续
6、顺子：数字是连续，花色不一样
7、三条：其中3张牌数字一样，另外2张牌数字不一样
8、两对：其中2张牌数字一样，另外其中2张牌数字一样，最后一张数字不一样
9、一对：其中2张牌数字一样，另外数字不一样
10、高牌：什么都不是
*/
const int Modular = 16, Divider = 256, DefaultReturn = 10, HandSize = 5;
enum class Rank {
  Two = 2,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  J,
  Q,
  K,
  A
};
enum class Suit { Diamond = 1, Club, Heart, Spade };
inline int suit(const int card) { return card / Divider; }
inline int rank(const int card) { return card % Modular; }
inline int card(const int suit, const int rank) {
  return suit * Divider + rank;
}
bool isSameSuit(const std::vector<int>& hand) {
  std::set<int> suits;
  for (const auto& card : hand) suits.insert(suit(card));

  return suits.size() == 1;
}
// firstCardRank = rank(hand.front()) as default
bool isSeq(const std::vector<int>& hand, int firstCardRank) {
  if (firstCardRank > (int)Rank::Ten) 
    return false;
  --firstCardRank;
  for (const auto& card : hand) {
    if (rank(card) == firstCardRank + 9 || rank(card) == firstCardRank + 1)
      firstCardRank = rank(card);
    else
      return false;
  }
  return true;
}
// diffRank.first: the counter of same card rank
// diffRank.second: the counter of .first
// for example: {{4, 1}, {1, 1}} or {{3,1}, {1, 2}} ...
bool sameRank(const std::vector<int>& hand,
              const std::map<int, int>& diffRank) {
  auto diff(diffRank);
  std::map<int, int> ranks;
  for (const auto& card : hand) ++ranks[rank(card)];
  for (const auto& r : ranks) {
    auto isFind = diff.find(r.second);
    if (isFind == diff.end()) return false;

    if (--isFind->second < 0) return false;
  }
  return true;
}
bool one(const std::vector<int>& hand) {
  return isSeq(hand, static_cast<int>(Rank::Ten)) && isSameSuit(hand);
}
bool two(const std::vector<int>& hand) {
  int firstCardRank = rank(hand.front());
  return firstCardRank != static_cast<int>(Rank::Ten) && isSameSuit(hand) &&
         isSeq(hand, firstCardRank);
}
bool three(const std::vector<int>& hand) {
  auto rankDiff = std::map<int, int>{{4, 1}, {1, 1}};
  return sameRank(hand, rankDiff);
}
bool four(const std::vector<int>& hand) {
  auto rankDiff = std::map<int, int>{{3, 1}, {2, 1}};
  return sameRank(hand, rankDiff);
}
bool five(const std::vector<int>& hand) {
  int firstCardRank = rank(hand.front());
  return isSameSuit(hand) && !isSeq(hand, firstCardRank);
}
bool six(const std::vector<int>& hand) {
  int firstCardRank = rank(hand.front());
  return !isSameSuit(hand) && isSeq(hand, firstCardRank);
}
bool seven(const std::vector<int>& hand) {
  auto rankDiff = std::map<int, int>{{3, 1}, {1, 2}};
  return sameRank(hand, rankDiff);
}
bool eight(const std::vector<int>& hand) {
  auto rankDiff = std::map<int, int>{{2, 2}, {1, 1}};
  return sameRank(hand, rankDiff);
}
bool nine(const std::vector<int>& hand) {
  auto rankDiff = std::map<int, int>{{2, 1}, {1, 3}};
  return sameRank(hand, rankDiff);
}
int findBest(
    const std::vector<int>& input,
    const std::vector<std::function<bool(const std::vector<int>&)>>& funVec) {
  int min = DefaultReturn;
  auto hand(input);

  std::sort(hand.begin(), hand.end(),
            [](const int lhs, const int rhs) { return rank(lhs) < rank(rhs); });

  if (hand.size() == HandSize) {
    for (int i = 0; i < funVec.size(); ++i) {
      if (funVec[i](hand)) {
        min = std::min(min, i);
        break;
      }
    }
  } else {
    for (int s = static_cast<int>(Suit::Diamond);
         s <= static_cast<int>(Suit::Spade); ++s) {
      for (int r = static_cast<int>(Rank::Two); r <= static_cast<int>(Rank::A);
           ++r) {
        // check whether card(s, r) is exit
        auto isExist = std::find(hand.begin(), hand.end(), card(s, r));
        // if not found, push it back and run backtrack
        if (isExist == hand.end()) {
          std::vector<int> backTrack(hand);
          backTrack.push_back(card(s, r));
          if (hand.size() <= HandSize) {
            min = std::min(findBest(backTrack, funVec), min);
          }
          // backtrack end
        }
      }
    }
  }
  return min;
}
int f(const std::vector<int>& input) {
  auto funVec = std::vector<std::function<bool(const std::vector<int>&)>>{
      one, two, three, four, five, six, seven, eight, nine};
  auto hand(input);

  // remove joker
  for (auto it = hand.begin(); it != hand.end();) {
    if (*it > card(static_cast<int>(Suit::Spade), static_cast<int>(Rank::A)))
      it = hand.erase(it);
    else
      ++it;
  }

  return findBest(hand, funVec) + 1;
}
int main() {
  std::vector<std::vector<int>> tests{
      {0x102, 0x203, 0x104, 0x610, 0x50f},
      {0x10a, 0x10b, 0x10c, 0x10d, 0x10e},   // 1
      {0x102, 0x103, 0x104, 0x105, 0x106},   // 2
      {0x102, 0x202, 0x302, 0x402, 0x107},   // 3
      {0x102, 0x202, 0x302, 0x407, 0x107},   // 4
      {0x10e, 0x102, 0x103, 0x104, 0x106},   // 5
      {0x20e, 0x102, 0x103, 0x104, 0x105},   // 6
      {0x102, 0x202, 0x302, 0x406, 0x107},   // 7
      {0x102, 0x202, 0x306, 0x406, 0x107},   // 8
      {0x102, 0x202, 0x305, 0x406, 0x107},   // 9
      {0x102, 0x203, 0x305, 0x406, 0x107}};  // 10
  std::cout << f(tests[0]);
}