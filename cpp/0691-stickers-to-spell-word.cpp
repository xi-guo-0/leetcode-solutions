#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

class Solution {
public:
  int minStickers(std::vector<std::string> &stickers, std::string target) {
    constexpr int INVALID = -1;
    const int NUM_STICKERS = stickers.size();
    const int TARGET_SIZE = target.size();
    const int NUM_LAYOUTS = (1 << TARGET_SIZE);
    long letter_to_stickers[26] = {};
    int dp[1 << 15];

    for (int i = 0; i < NUM_STICKERS; ++i)
      for (char c : stickers[i])
        letter_to_stickers[c - 'a'] |= (1L << i);
    std::memset(dp, INVALID, sizeof(dp));
    dp[0] = 0;

    for (int layout = 0; layout < NUM_LAYOUTS; ++layout) {
      if (dp[layout] == INVALID)
        continue;
      int letter = -1;
      for (int i_target = 0; i_target < TARGET_SIZE; ++i_target) {
        if (!((layout >> i_target) & 1) &&
            (letter_to_stickers[target[i_target] - 'a'] != 0)) {
          letter = target[i_target] - 'a';
          break;
        }
      }
      if (letter == -1)
        break;
      for (int i_sticker = 0; i_sticker < NUM_STICKERS; ++i_sticker) {
        if (((letter_to_stickers[letter] >> i_sticker) & 1) == 0)
          continue;
        int next_layout = layout;
        for (char c_sticker : stickers[i_sticker]) {
          for (int i_target = 0; i_target < TARGET_SIZE; ++i_target) {
            if (target[i_target] == c_sticker &&
                ((next_layout >> i_target) & 1) == 0) {
              next_layout |= (1 << i_target);
              break;
            }
          }
        }
        dp[next_layout] = (dp[next_layout] == INVALID)
                              ? (dp[layout] + 1)
                              : std::min(dp[next_layout], dp[layout] + 1);
      }
    }
    return dp[NUM_LAYOUTS - 1];
  }
};
