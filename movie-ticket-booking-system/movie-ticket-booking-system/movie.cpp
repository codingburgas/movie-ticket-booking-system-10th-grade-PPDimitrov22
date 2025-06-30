#include <iostream>
#include "movie.h"

void displayMovieDetails(const Movie& movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Language: " << movie.language << std::endl;
    std::cout << "Genre: " << movie.genre << std::endl;
    std::cout << "Release Date: " << movie.releaseDate << std::endl;
}

int findMovieByTitle(const std::vector<Movie>& movies, const std::string& title) {
    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].title == title) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void listMovies(const std::vector<Movie>& movies) {
    for (const auto& movie : movies) {
        std::cout << movie.title << " (" << movie.releaseDate << ")" << std::endl;
    }
}
