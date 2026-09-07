bool comp(vector<string>& a, vector<string>& b) {
    return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
}

void travelTheWorld(
    vector<vector<string>>& tickets, string& airport, 
    unordered_map<string, vector<int>>& srcTickets, vector<bool>& ticketUsed,
    vector<string>& itinerary
) {
    for(auto ticket: srcTickets[airport]) {
        if(!ticketUsed[ticket]) {
            ticketUsed[ticket] = true;
            travelTheWorld(tickets, tickets[ticket][1], srcTickets, ticketUsed, itinerary);
        }
    }

    itinerary.push_back(airport);
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // in this problem, what I understand is that we have a bunch of tickets, and we have to find a nice order in which all the airports visited are in a alphabetical order, are in a lexical order, from lowest to highest, And after this order is satisfied, what else do we need to ensure that also we need to ensure that all the tickets are used.
        // to find the relation of chronological order between two tickets or to figure out if one ticket can be used after another, immediately after another, if we are using ticket two after ticket one, then ticket one's destination airport must match with the source airport of ticket two of the second ticket only then can we use the second ticket after we have used the first ticket.
        // so first, we can make an adjacency list in which we store for each ticket, if another ticket can be used immediately after this one, so the adjacency list of ticket one would include all the tickets, let's say ticket, three ticket, four ticket, seven, those tickets, that have the same Departures, airport, as the destination airport of ticket one.
        // I tried sorting the tickets, and then tried to map the tickets that I can use from a given station, and with that map, I tried to use all the tickets in their lexographical order, but that did not work, because that consumed a lot of time.
        // on another note, I have a bunch of tickets, and if I use a ticket once, then that ticket is invalid, so if I use a ticket, and I end up at an airport, that from where I cannot go anywhere else, and I am stuck, and I still have some tickets left, then I will not be able to construct the itinerary, because the itinerary wants me to visit all the airports, and use all the tickets only once, no less than that, no more than that.
        // so I have to make sure that I do not get stuck at any airport. Except one that is my, that is my last airport that I visit.
        // now to make sure that I do not get stuck at any airport, I have to make sure that the number of tickets that lead me to the airport is equal to the number of tickets that depart from that airport.
        // to understand why this is important, let's say we have an airport X, and we have 3 tickets, that have this airport, either in the departure airport of that ticket or in the arrival airport of that ticket. So let's say we have 2 tickets that have a rival airport as airport X and we have one ticket that has Departure airport as airport X.
        // here it is clearly visible that We have two tickets that lead to airport X and one ticket that departs from Airport X, that means that these two, the number of these two kinds of tickets for airport X is not equal.
        // to understand how this can get us stuck at this airport, we have to understand, we have to go through this scenario.
        // let's say, uh, the two tickets that have arrival airport as Airport X are like are are like one departs from Airport Y and leads to Airport X, the other one departs from Z and leads to Airport X, so I fly from Airport Y to Airport X, I reach there.
        // And the one that. The one that. Departs from airport X leads to airport A, let's suppose, so I go from Y to X, and then I go from X to A, and there is some other route involving a whole lot of tickets from A to the airport Z. Now, I have, yeah.
        // So now I have from Z, I can go from from Z to X. I have this ticket. I have not used it yet. I use it. I go to X but now there's no ticket. left that has departure airport as X.
        // But, what if I already used the other tickets? And there's no ticket left, then there's no worry if I do not have any ticket that departs from X because all the other tickets have been used and I have kind of reconstructed my itinerary, which was my goal in the beginning.
        // that means that only one airport can have more tickets that lead to it than the number of tickets that depart from it, so that it is the ending airport of the itinerary, and only one airport can have More tickets that depart from it, then the number of tickets that lead to it, and that airport can be the starting airport of our itinerary.
        // and all the other airports must have equal number of tickets that lead to it, and equal number of tickets that depart from it.
        // now that we have ascertained, if it is possible to reconstruct the itinerary, and we know the starting point. As it is the point which has more departing tickets, then the tickets that lead to it.
        // to figure out a way in the minimal possible time, what we can do is, we can use maybe a counterintuitive approach, where we start from the beginning point, whatever it is, here I suppose it is JFK, and we start from JFK, we keep following the tickets in the lexicographical order, and then, uh, until we get stuck.
        // So if we do not get stuck, we keep, you know, adding all the tickets. I mean, uh, using all the tickets and visiting these airports, uh, and at this point, unless we get stuck, we haven't constructed the itinerary yet. At the point when we get stuck, we know that the, the, the, the 1st time that we get stuck is, uh, the point is the ending point of the itinerary, because uh, from there we can't go anywhere.
        // So we add it at the front of our, at the front of our itinerary, and we backtrack. We backtrack, uh, uh, the airports that we have that we, um, We backtrack through the airports that we visited in order to visit this airport where we got stuck.
        // and as we backtrack, we know, these are the airports that lead to that lead to the final airport, so we keep adding them in this order only, so if we, if we, uh, if the last airport is, let's say, uh, KFG and there's some other airport which led us to this airport, let's say, XYZ, and there, okay, so we must add XYZ in front of KFG, because that's the way it, the itinerary will work.
        // We will 1st have to visit XYZ in order to get to KFG. We keep backtracking through the airports and keep adding these airports to our itinerary this way.
        // and while backtracking, if we get to an airport, which still has tickets left, then what do we do is, we know that we can't get add this airport to the itinerary because it, there is still a way to explore other tickets that goes from this airport.
        // So what we do is we start from this airport until we cycle back to this airport. Now, as we have cycled back to this airport, uh, we do the same thing as we were doing earlier, we backtrack, uh, that path that we took to cycle back to this airport, uh, so that it maintains the order of visiting these airports.

        sort(tickets.begin(), tickets.end(), comp);

        vector<vector<int>> adjList(tickets.size());

        unordered_map<string, vector<int>> srcTickets;

        for(int i = 0; i < tickets.size(); i++) {
            auto ticket = tickets[i];
            string srcAirport = ticket[0];
            if(srcTickets.find(srcAirport) == srcTickets.end()) {
                vector<int> temp;
                srcTickets.insert({srcAirport, temp});
            }
            srcTickets[srcAirport].push_back(i);
        }

        for(int i = 0; i < tickets.size(); i++) {
            auto ticket = tickets[i];
            auto destAirport = ticket[1];
            vector<int> temp = srcTickets[destAirport];
            adjList[i] = temp;
        }

        vector<bool> ticketUsed(tickets.size(), false);

        string srcAirport = "JFK";

        vector<string> itinerary;

        travelTheWorld(tickets, srcAirport, srcTickets, ticketUsed, itinerary);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};