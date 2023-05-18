#include <string>
#include <map>
enum class ScoreState
{
    EqualScores,
    AdvantageOrWinScore,
    RunningScore
};
ScoreState get_score_state(int p1_score, int p2_score)
{
    if (p1_score == p2_score)
    {
        return ScoreState::EqualScores;
    }
    else if (p1_score >= 4 || p2_score >= 4)
    {
        return ScoreState::AdvantageOrWinScore;
    }
    else
    {
        return ScoreState::RunningScore;
    }
}

const std::string get_equal_tennis_score(int p1_score, std::map<int, std::string> score_name, std::string& score)
{
    if (p1_score >= 3)
        score = "Deuce";
    else
        score = score_name.at(p1_score) + "-All";
    return score;
}

const std::string get_advantage_or_win_tennis_score(int p1_score, int p2_score, std::map<int, std::string> score_name,
                                                    std::string& score)
{
    int diff = p1_score - p2_score;
    switch (diff)
    {
        case 1: score = "Advantage player1"; break;
        case -1: score = "Advantage player2"; break;
        default: {
            if (diff > 0)
                score = "Win for player1";
            else
                score = "Win for player2";
            break;
        }
    }
    return score;
}

const std::string get_running_tennis_score(int p1_score, int p2_score, std::map<int, std::string> score_name,
                                           std::string& score)
{
    score = score_name.at(p1_score) + "-" + score_name.at(p2_score);
    return score;
}

const std::string get_tennis_score(int p1_score, int p2_score)
{
    ScoreState                       score_state = get_score_state(p1_score, p2_score);
    std::string                      score       = "";
    const std::map<int, std::string> score_name  = {{0, "Love"}, {1, "Fifteen"}, {2, "Thirty"}, {3, "Forty"}};

    switch (score_state)
    {
        case ScoreState::EqualScores: {
            score = get_equal_tennis_score(p1_score, score_name, score);
            break;
        }

        case ScoreState::AdvantageOrWinScore: {
            score = get_advantage_or_win_tennis_score(p1_score, p2_score, score_name, score);
            break;
        }

        case ScoreState::RunningScore: {
            score = get_running_tennis_score(p1_score, p2_score, score_name, score);
            break;
        }

        default: break;
    }
    return score;
}
