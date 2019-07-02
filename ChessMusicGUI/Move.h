#pragma once

#include <QStandardItemModel>
#include <QObject>
#include <QString>
#include <iostream>
#include <string>

namespace Models {
	
	class Move {

	public:
		Move(
			int fullmove_number = 0,
			bool turn = false, 
			std::string san = "", 
			std::string lan = "", 
			int score = 0,
			int score_shift = 0,
			float score_shift_category = 0.0f,
			int move_count = 0, 
			std::string best_move = "",
			int best_move_score = 0,
			int best_move_score_difference = 0,
			int best_move_score_difference_category = 0,
			bool is_check = false,
			bool is_capture = false,
			bool is_castling = false,
			int possible_moves_count = 0,
			int is_capture_count = 0,
			std::string attackers_white = "",
			int attackers_count_white = 0,
			std::string threatened_pieces_white = "",
			int threatened_pieces_count_white = 0,
			std::string guards_white = "",
			int guards_count_white = 0,
			std::string guarded_pieces_white = "",
			int guarded_pieces_count_white = 0,
			std::string threatened_guarded_pieces_white = "",
			int threatened_guarded_pieces_count_white = 0,
			std::string unopposed_threats_white = "",
			int unopposed_threats_count_white = 0,
			std::string attackers_black = "",
			int attackers_count_black = 0,
			std::string threatened_pieces_black = "",
			int threatened_pieces_count_black = 0,
			std::string guards_black = "",
			int guards_count_black = 0,
			std::string guarded_pieces_black = "",
			int guarded_pieces_count_black = 0,
			std::string threatened_guarded_pieces_black = "",
			int threatened_guarded_pieces_count_black = 0,
			std::string unopposed_threats_black = "",
			int unopposed_threats_count_black = 0,
			int threatened_pieces_centipawn_white = 0,
			int guarded_pieces_centipawn_white = 0,
			int threatened_guarded_pieces_centipawn_white = 0,
			int unopposed_threats_centipawn_white = 0,
			int threatened_pieces_centipawn_black = 0,
			int guarded_pieces_centipawn_black = 0,
			int threatened_guarded_pieces_centipawn_black = 0,
			int unopposed_threats_centipawn_black = 0
		);

		int fullmove_number() const;
		bool turn() const;
		std::string san() const;
		std::string lan() const;
		int score() const;
		int score_shift() const;
		float score_shift_category() const;
		int move_count() const;
		std::string best_move() const;
		int best_move_score() const;
		int best_move_score_difference() const;
		int best_move_score_difference_category() const;
		bool is_check() const;
		bool is_capture() const;
		bool is_castling() const;
		
		int possible_moves_count() const;
		int is_capture_count() const;
		
		std::string attackers_white() const;
		int attackers_count_white() const;
		std::string threatened_pieces_white() const;
		int threatened_pieces_count_white() const;
		
		std::string guards_white() const;
		int guards_count_white() const;
		std::string guarded_pieces_white() const;
		int guarded_pieces_count_white() const;
		
		std::string threatened_guarded_pieces_white() const;
		int threatened_guarded_pieces_count_white() const;
		std::string unopposed_threats_white() const;
		int unopposed_threats_count_white() const;

		std::string attackers_black() const;
		int attackers_count_black() const;
		std::string threatened_pieces_black() const;
		int threatened_pieces_count_black() const;

		std::string guards_black() const;
		int guards_count_black() const;
		std::string guarded_pieces_black() const;
		int guarded_pieces_count_black() const;

		std::string threatened_guarded_pieces_black() const;
		int threatened_guarded_pieces_count_black() const;
		std::string unopposed_threats_black() const;
		int unopposed_threats_count_black() const;

		int threatened_pieces_centipawn_white() const;
		int guarded_pieces_centipawn_white() const;
		int threatened_guarded_pieces_centipawn_white() const;
		int unopposed_threats_centipawn_white() const;

		int threatened_pieces_centipawn_black() const;
		int guarded_pieces_centipawn_black() const;
		int threatened_guarded_pieces_centipawn_black() const;
		int unopposed_threats_centipawn_black() const;

		friend std::ostream& operator<<(std::ostream& out, const Move& move);

	private:
		int m_fullmove_number;
		bool m_turn;
		std::string m_san;
		std::string m_lan;
		int m_score;
		int m_score_shift;
		float m_score_shift_category;
		int m_move_count;
		std::string m_best_move;
		int m_best_move_score;
		int m_best_move_score_difference;
		int m_best_move_score_difference_category;
		bool m_is_check;
		bool m_is_capture;
		bool m_is_castling;
		
		int m_possible_moves_count;
		int m_is_capture_count;
		
		std::string m_attackers_white;
		int m_attackers_count_white;
		std::string m_threatened_pieces_white;
		int m_threatened_pieces_count_white;

		std::string m_guards_white;
		int m_guards_count_white;
		std::string m_guarded_pieces_white;
		int m_guarded_pieces_count_white;

		std::string m_threatened_guarded_pieces_white;
		int m_threatened_guarded_pieces_count_white;
		std::string m_unopposed_threats_white;
		int m_unopposed_threats_count_white;

		std::string m_attackers_black;
		int m_attackers_count_black;
		std::string m_threatened_pieces_black;
		int m_threatened_pieces_count_black;

		std::string m_guards_black;
		int m_guards_count_black;
		std::string m_guarded_pieces_black;
		int m_guarded_pieces_count_black;

		std::string m_threatened_guarded_pieces_black;
		int m_threatened_guarded_pieces_count_black;
		std::string m_unopposed_threats_black;
		int m_unopposed_threats_count_black;

		int m_threatened_pieces_centipawn_white;
		int m_guarded_pieces_centipawn_white;
		int m_threatened_guarded_pieces_centipawn_white;
		int m_unopposed_threats_centipawn_white;

		int m_threatened_pieces_centipawn_black;
		int m_guarded_pieces_centipawn_black;
		int m_threatened_guarded_pieces_centipawn_black;
		int m_unopposed_threats_centipawn_black;
	};
}