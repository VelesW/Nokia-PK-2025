#pragma once

#include "IEventsHandler.hpp"
#include "Logger/PrefixedLogger.hpp"
#include "Context.hpp"
#include <optional>

namespace ue
{

class BaseState : public IEventsHandler
{
public:
    BaseState(Context& context, const std::string& name);
    ~BaseState() override;

    // ITimerEventsHandler interface
    void handleTimeout() override;

    // IBtsEventsHandler interface
    void handleSib(common::BtsId btsId) override;
    void handleAttachAccept() override;
    void handleAttachReject() override;

    // CallingState
    virtual void handleCallDropped();
    virtual void handleDisconnected();
    virtual void handleUIEnding();
    virtual void handleUICalling(std::optional<std::size_t> selectedIndex);
    virtual void handleCallAccepted(common::PhoneNumber recipient);
    virtual void handleUnknownRecipient(common::PhoneNumber recipient);

protected:
    Context& context;
    common::PrefixedLogger logger;
};

}
