# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 13:29:46 by okrahl            #+#    #+#              #
#    Updated: 2024/11/04 16:54:29 by okrahl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincl

# Directories
SRCDIR = src
INCLDIR = incl
OBJDIR = obj

# Files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE = bureaucrat

GREEN = "\033[0;32m"
NC = "\033[0m"

# Default target
all: $(EXECUTABLE)
	@echo $(GREEN)bureaucrat is ready$(NC)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean up
clean:
	rm -f $(OBJDIR)/*.o
	-rmdir $(OBJDIR) # Use - to ignore errors if directory doesn't exist
	rm -f *_shrubbery # Remove all shrubbery files

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re