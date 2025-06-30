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
void addMovie(std::vector<Movie>& movies) {
    Movie newMovie;
    std::cin.ignore();

    std::cout << "Enter movie title: ";
    std::getline(std::cin, newMovie.title);

    std::cout << "Enter language: ";
    std::getline(std::cin, newMovie.language);

    std::cout << "Enter genre: ";
    std::getline(std::cin, newMovie.genre);

    std::cout << "Enter release date: ";
    std::getline(std::cin, newMovie.releaseDate);

    movies.push_back(newMovie);
    std::cout << "Movie added successfully.\n";
}

void removeMovie(std::vector<Movie>& movies) {
    std::cin.ignore();

    std::string title;
    std::cout << "Enter movie title to remove: ";
    std::getline(std::cin, title);

    auto it = std::remove_if(movies.begin(), movies.end(), [&](const Movie& m) {
        return m.title == title;
        });

    if (it != movies.end()) {
        movies.erase(it, movies.end());
        std::cout << "Movie removed successfully.\n";
    }
    else {
        std::cout << "Movie not found.\n";
    }
}
