#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

struct Movie {
    std::string title;
    std::string language;
    std::string genre;
    std::string releaseDate;
};

void displayMovieDetails(const Movie& movie);
int findMovieByTitle(const std::vector<Movie>& movies, const std::string& title);
void listMovies(const std::vector<Movie>& movies);
void addMovie(std::vector<Movie>& movies);
void removeMovie(std::vector<Movie>& movies);

#endif
