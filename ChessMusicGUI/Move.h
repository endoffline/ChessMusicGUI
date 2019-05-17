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
			int turn = 0, 
			std::string san = "", 
			std::string lan = "", 
			int score = 0, 
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
			std::string attackers = "",
			int attackers_count = 0,
			std::string threatened_pieces = "",
			int threatened_pieces_count = 0,
			std::string guards = "",
			int guards_count = 0,
			std::string guarded_pieces = "",
			int guarded_pieces_count = 0,
			std::string threatened_guarded_pieces = "",
			int threatened_guarded_pieces_count = 0,
			std::string unopposed_threats = "",
			int unopposed_threats_count = 0
		);

		int turn() const;
		std::string san() const;
		std::string lan() const;
		int score() const;
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
		
		std::string attackers() const;
		int attackers_count() const;
		std::string threatened_pieces() const;
		int threatened_pieces_count() const;
		
		std::string guards() const;
		int guards_count() const;
		std::string guarded_pieces() const;
		int guarded_pieces_count() const;
		
		std::string threatened_guarded_pieces() const;
		int threatened_guarded_pieces_count() const;
		std::string unopposed_threats() const;
		int unopposed_threats_count() const;

		friend std::ostream& operator<<(std::ostream& out, const Move& move);

	private:
		int m_turn;
		std::string m_san;
		std::string m_lan;
		int m_score;
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
		
		std::string m_attackers;
		int m_attackers_count;
		std::string m_threatened_pieces;
		int m_threatened_pieces_count;

		std::string m_guards;
		int m_guards_count;
		std::string m_guarded_pieces;
		int m_guarded_pieces_count;

		std::string m_threatened_guarded_pieces;
		int m_threatened_guarded_pieces_count;
		std::string m_unopposed_threats;
		int m_unopposed_threats_count;
	};
}