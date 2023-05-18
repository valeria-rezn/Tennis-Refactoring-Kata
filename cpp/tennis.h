#ifndef TENNIS_H
#define TENNIS_H

#include <string>
#include <map>

enum class ScoreState
{
    EqualScores,
    AdvantageOrWinScore,
    RunningScore
};

const std::string get_tennis_score(int p1_score, int p2_score);

#endif