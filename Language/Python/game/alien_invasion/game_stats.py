class GameStats():
    """track statistics"""

    def __init__(self, ai_set):
        """initialize statistics"""
        self.ai_set = ai_set
        self.reset_stats()
        self.active = False
        self.score = 0

    def reset_stats(self):
        """initialize the info which can be changed during the game"""
        self.ships_left = self.ai_set.ship_limit
