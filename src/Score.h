/*
 * Score.h
 *
 *  Created on: Oct 13, 2017
 *      Author: antonio
 */

#ifndef SRC_SCORE_H_
#define SRC_SCORE_H_

class Score {
private:
	unsigned int points;
public:
	Score(): points(0) {}
	virtual ~Score();
	void addPoints(int newPoints);
	inline unsigned int getPoints(){return this->points;}

	Score(const Score& that) = delete;
	Score& operator= (const Score&) = delete;

};

#endif /* SRC_SCORE_H_ */
