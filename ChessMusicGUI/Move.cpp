#include "Move.h"
#include <QObject>
#include <QString>

namespace Models {

	Move::Move(
		int turn,
		std::string san,
		std::string lan,
		int score,
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
		std::string attackers,
		int attackers_count,
		std::string threatened_pieces,
		int threatened_pieces_count,
		std::string guards,
		int guards_count,
		std::string guarded_pieces,
		int guarded_pieces_count,
		std::string threatened_guarded_pieces,
		int threatened_guarded_pieces_count,
		std::string unopposed_threats,
		int unopposed_threats_count
	) : m_turn(turn),
		m_san(san),
		m_lan(lan),
		m_score(score),
		m_move_count(move_count),
		m_best_move_score(best_move_score),
		m_best_move_score_difference(best_move_score_difference),
		m_best_move_score_difference_category(best_move_score_difference_category),
		m_is_check(is_check),
		m_is_capture(is_capture),
		m_is_castling(is_castling),
		m_possible_moves_count(possible_moves_count),
		m_is_capture_count(is_capture_count),
		m_attackers(attackers),
		m_attackers_count(attackers_count),
		m_threatened_pieces(threatened_pieces),
		m_threatened_pieces_count(threatened_pieces_count),
		m_guards(guards),
		m_guards_count(guards_count),
		m_guarded_pieces(guarded_pieces),
		m_guarded_pieces_count(guarded_pieces_count),
		m_threatened_guarded_pieces(threatened_guarded_pieces),
		m_threatened_guarded_pieces_count(threatened_guarded_pieces_count),
		m_unopposed_threats(unopposed_threats),
		m_unopposed_threats_count(unopposed_threats_count) {

	}

	int Move::turn() const {
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

	std::string Move::attackers() const {
		return m_attackers;
	}

	int Move::attackers_count() const {
		return m_attackers_count;
	}

	std::string Move::threatened_pieces() const {
		return m_threatened_pieces;
	}

	int Move::threatened_pieces_count() const {
		return m_threatened_guarded_pieces_count;
	}

	std::string Move::guards() const {
		return m_guards;
	}

	int Move::guards_count() const {
		return m_guards_count;
	}
	std::string Move::guarded_pieces() const {
		return m_guarded_pieces;
	}

	int Move::guarded_pieces_count() const {
		return m_guarded_pieces_count;
	}

	std::string Move::threatened_guarded_pieces() const {
		return m_threatened_guarded_pieces;
	}

	int Move::threatened_guarded_pieces_count() const {
		return m_threatened_guarded_pieces_count;
	}

	std::string Move::unopposed_threats() const {
		return m_unopposed_threats;
	}

	int Move::unopposed_threats_count() const {
		return m_unopposed_threats_count;
	}

	std::ostream& operator<<(std::ostream& out, const Move& move) {
		out << "Move " << move.m_turn << ": " << ", Score: " << move.m_score << std::endl;
		return out;
	}
}

