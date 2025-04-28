#include "CallingState.hpp"
#include "ConnectedState.hpp"
#include "NotConnectedState.hpp"
#include <chrono>

using namespace std::chrono;

namespace ue 
{
    // TODO: Consider call talk state
    CallingState::CallingState(Context &context) : BaseState(context, "Call state") 
    {
        logger.logInfo("Call state");
        context.timer.startTimer(60s);
    }

    void CallingState::handleTimeout() {
        logger.logInfo("Call timeout");
        context.user.showAlert("Call timeout", "");
    }

    void CallingState::handleCallDropped() {
        // Implementation for handling call dropped
    }

    void CallingState::handleDisconnected() {
        // Implementation for handling disconnection
    }

    void CallingState::handleUIEnding() {
        logger.logInfo("Call was cancelled");
        // TODO: context.bts.sendCallEnding()
        context.setState<ConnectedState>();
    }
    // CHANGE

    void CallingState::handleUICalling(std::optional<std::size_t> selectedIndex) {
        // Implementation for handling UI calling
    }

    void CallingState::handleCallAccepted(common::PhoneNumber recipient) {
        // Implementation for handling call accepted
    }

    void CallingState::handleUnknownRecipient(common::PhoneNumber recipient) {
        // Implementation for handling unknown recipient
    }
} 