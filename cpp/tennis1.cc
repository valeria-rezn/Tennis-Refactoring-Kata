#include <string>
#include <map>
const std::string tennis_score(int p1_score, int p2_score) {
    std::string score = ""; 
    const std::map<int, std::string> score_name = 
    {
        {0, "Love"},
        {1, "Fifteen"},
        {2, "Thirty"}, 
        {3, "Forty"}
    };

    if (p1_score==p2_score)
    {
        if (p1_score >= 3)
            score = "Deuce";
        else
            score = score_name.at(p1_score) + "-All";
    }
    else if (p1_score>=4 || p2_score>=4)
    {
        
        int diff = p1_score-p2_score;
        switch (diff)
        {
            case 1: score = "Advantage player1"; break;
            case -1: score = "Advantage player2"; break;
            default:
                if (diff > 0)
                    score = "Win for player1";
                else
                    score = "Win for player2";
                break;
        }
    }
    else
    {
        score = score_name.at(p1_score) + "-" + score_name.at(p2_score);
    }

    return score;
    
}
