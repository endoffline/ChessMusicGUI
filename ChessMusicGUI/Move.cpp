#include "Move.h"
#include <QObject>
#include <QString>

namespace Models {

	Move::Move(
		int fullmove_number,
		bool turn,
		std::string san,
		std::string lan,
		int score,
		int score_shift,
		float score_shift_category,
		int move_count,
		std::string best_move,
		int best_move_score,
		int best_move_score_difference,
		int best_move_score_difference_category,
		bool is_check,
		bool is_capture,
		bool is_castling,
		int possible_moves_count,
		int is_capture_count,
		std::string attackers_white,
		int attackers_count_white,
		std::string threatened_pieces_white,
		int threatened_pieces_count_white,
		std::string guards_white,
		int guards_count_white,
		std::string guarded_pieces_white,
		int guarded_pieces_count_white,
		std::string threatened_guarded_pieces_white,
		int threatened_guarded_pieces_count_white,
		std::string unopposed_threats_white,
		int unopposed_threats_count_white,
		std::string attackers_black,
		int attackers_count_black,
		std::string threatened_pieces_black,
		int threatened_pieces_count_black,
		std::string guards_black,
		int guards_count_black,
		std::string guarded_pieces_black,
		int guarded_pieces_count_black,
		std::string threatened_guarded_pieces_black,
		int threatened_guarded_pieces_count_black,
		std::string unopposed_threats_black,
		int unopposed_threats_count_black,
		int threatened_pieces_centipawn_white,
		int guarded_pieces_centipawn_white,
		int threatened_guarded_pieces_centipawn_white,
		int unopposed_threats_centipawn_white,
		int threatened_pieces_centipawn_black,
		int guarded_pieces_centipawn_black,
		int threatened_guarded_pieces_centipawn_black,
		int unopposed_threats_centipawn_black,
		int attack_defense_relation
	) : m_fullmove_number(fullmove_number),
		m_turn(turn),
		m_san(san),
		m_lan(lan),
		m_score(score),
		m_score_shift(score_shift),
		m_score_shift_category(score_shift_category),
		m_move_count(move_count),
		m_best_move(best_move),
		m_best_move_score(best_move_score),
		m_best_move_score_difference(best_move_score_difference),
		m_best_move_score_difference_category(best_move_score_difference_category),
		m_is_check(is_check),
		m_is_capture(is_capture),
		m_is_castling(is_castling),
		m_possible_moves_count(possible_moves_count),
		m_is_capture_count(is_capture_count),
		m_attackers_white(attackers_white),
		m_attackers_count_white(attackers_count_white),
		m_threatened_pieces_white(threatened_pieces_white),
		m_threatened_pieces_count_white(threatened_pieces_count_white),
		m_guards_white(guards_white),
		m_guards_count_white(guards_count_white),
		m_guarded_pieces_white(guarded_pieces_white),
		m_guarded_pieces_count_white(guarded_pieces_count_white),
		m_threatened_guarded_pieces_white(threatened_guarded_pieces_white),
		m_threatened_guarded_pieces_count_white(threatened_guarded_pieces_count_white),
		m_unopposed_threats_white(unopposed_threats_white),
		m_unopposed_threats_count_white(unopposed_threats_count_white),
		m_attackers_black(attackers_black),
		m_attackers_count_black(attackers_count_black),
		m_threatened_pieces_black(threatened_pieces_black),
		m_threatened_pieces_count_black(threatened_pieces_count_black),
		m_guards_black(guards_black),
		m_guards_count_black(guards_count_black),
		m_guarded_pieces_black(guarded_pieces_black),
		m_guarded_pieces_count_black(guarded_pieces_count_black),
		m_threatened_guarded_pieces_black(threatened_guarded_pieces_black),
		m_threatened_guarded_pieces_count_black(threatened_guarded_pieces_count_black),
		m_unopposed_threats_black(unopposed_threats_black),
		m_unopposed_threats_count_black(unopposed_threats_count_black),
		m_threatened_pieces_centipawn_white(threatened_pieces_centipawn_white),
		m_guarded_pieces_centipawn_white(guarded_pieces_centipawn_white),
		m_threatened_guarded_pieces_centipawn_white(threatened_guarded_pieces_centipawn_white),
		m_unopposed_threats_centipawn_white(unopposed_threats_centipawn_white),
		m_threatened_pieces_centipawn_black(threatened_pieces_centipawn_black),
		m_guarded_pieces_centipawn_black(guarded_pieces_centipawn_black),
		m_threatened_guarded_pieces_centipawn_black(threatened_guarded_pieces_centipawn_black),
		m_unopposed_threats_centipawn_black(unopposed_threats_centipawn_black),
		m_attack_defense_relation(attack_defense_relation)
		{
	}

	int Move::fullmove_number() const {
		return m_fullmove_number;
	}

	bool Move::turn() const {
		return m_turn;
	}

	std::string Move::san() const {
		return m_san;
	}

	std::string Move::lan() const {
		return m_lan;
	}
	
	int Move::score() const {
		return m_score;
	}

	int Move::score_shift() const {
		return m_score_shift;
	}

	float Move::score_shift_category() const {
		return m_score_shift_category;
	}

	int Move::move_count() const {
		return m_move_count;
	}

	std::string Move::best_move() const {
		return m_best_move;
	}

	int Move::best_move_score() const {
		return m_best_move_score;
	}

	int Move::best_move_score_difference() const {
		return m_best_move_score_difference;
	}

	int Move::best_move_score_difference_category() const {
		return m_best_move_score_difference_category;
	}

	bool Move::is_check() const {
		return m_is_check;
	}

	bool Move::is_capture() const {
		return m_is_capture;
	}

	bool Move::is_castling() const {
		return m_is_castling;
	}

	int Move::possible_moves_count() const {
		return m_possible_moves_count;
	}

	int Move::is_capture_count() const {
		return m_is_capture_count;
	}

	std::string Move::attackers_white() const {
		return m_attackers_white;
	}

	int Move::attackers_count_white() const {
		return m_attackers_count_white;
	}

	std::string Move::threatened_pieces_white() const {
		return m_threatened_pieces_white;
	}

	int Move::threatened_pieces_count_white() const {
		return m_threatened_guarded_pieces_count_white;
	}

	std::string Move::guards_white() const {
		return m_guards_white;
	}

	int Move::guards_count_white() const {
		return m_guards_count_white;
	}
	std::string Move::guarded_pieces_white() const {
		return m_guarded_pieces_white;
	}

	int Move::guarded_pieces_count_white() const {
		return m_guarded_pieces_count_white;
	}

	std::string Move::threatened_guarded_pieces_white() const {
		return m_threatened_guarded_pieces_white;
	}

	int Move::threatened_guarded_pieces_count_white() const {
		return m_threatened_guarded_pieces_count_white;
	}

	std::string Move::unopposed_threats_white() const {
		return m_unopposed_threats_white;
	}

	int Move::unopposed_threats_count_white() const {
		return m_unopposed_threats_count_white;
	}

	std::string Move::attackers_black() const {
		return m_attackers_black;
	}

	int Move::attackers_count_black() const {
		return m_attackers_count_black;
	}

	std::string Move::threatened_pieces_black() const {
		return m_threatened_pieces_black;
	}

	int Move::threatened_pieces_count_black() const {
		return m_threatened_guarded_pieces_count_black;
	}

	std::string Move::guards_black() const {
		return m_guards_black;
	}

	int Move::guards_count_black() const {
		return m_guards_count_black;
	}
	std::string Move::guarded_pieces_black() const {
		return m_guarded_pieces_black;
	}

	int Move::guarded_pieces_count_black() const {
		return m_guarded_pieces_count_black;
	}

	std::string Move::threatened_guarded_pieces_black() const {
		return m_threatened_guarded_pieces_black;
	}

	int Move::threatened_guarded_pieces_count_black() const {
		return m_threatened_guarded_pieces_count_black;
	}

	std::string Move::unopposed_threats_black() const {
		return m_unopposed_threats_black;
	}

	int Move::unopposed_threats_count_black() const {
		return m_unopposed_threats_count_black;
	}

	int Move::threatened_pieces_centipawn_white() const {
		return m_threatened_pieces_centipawn_white;
	}

	int Move::guarded_pieces_centipawn_white() const {
		return m_guarded_pieces_centipawn_white;
	}

	int Move::threatened_guarded_pieces_centipawn_white() const {
		return m_threatened_guarded_pieces_centipawn_white;
	}

	int Move::unopposed_threats_centipawn_white() const {
		return m_unopposed_threats_centipawn_white;
	}


	int Move::threatened_pieces_centipawn_black() const {
		return m_threatened_pieces_centipawn_black;
	}

	int Move::guarded_pieces_centipawn_black() const {
		return m_guarded_pieces_centipawn_black;
	}

	int Move::threatened_guarded_pieces_centipawn_black() const {
		return m_threatened_guarded_pieces_centipawn_black;
	}

	int Move::unopposed_threats_centipawn_black() const {
		return m_unopposed_threats_centipawn_black;
	}

	int Move::attack_defense_relation() const {
		return m_attack_defense_relation;
	}


	std::ostream& operator<<(std::ostream& out, const Move& move) {
		out << "Move " << move.m_turn << ": " << ", Score: " << move.m_score << std::endl;
		return out;
	}
}

