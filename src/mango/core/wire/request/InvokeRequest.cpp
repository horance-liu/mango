#include "mango/core/wire/request/InvokeRequest.h"

#include <mango/core/except/PendingStepException.h>
#include <mango/core/runtime/Runner.h>

#include "mango/core/wire/response/SuccessResponse.h"
#include <mango/core/wire/response/PendingResponse.h>
#include "mango/core/wire/response/FailureResponse.h"

MANGO_NS_BEGIN

InvokeRequest::InvokeRequest(const std::string& id, InvokeArgs& args)
  : id(id)
  , args(std::move(args))
{
}

WireResponse* InvokeRequest::run(Runner& runner) const
{
    try {
        runner.invokeStep(id, args);
        return new SuccessResponse;
    } catch (const PendingStepException& e) {
        return new PendingResponse(e.getMsg());
    } catch (const ::std::runtime_error &e) {
        return new FailureResponse(e.what());
    } catch (const std::exception& ex) {
        return new FailureResponse(ex.what());
    } catch (const std::string& ex) {
        return new FailureResponse(ex);
    } catch (const char *ex) {
        return new FailureResponse(ex);
    } catch (...) {
        return new FailureResponse("Unknown exception");
    }
}

MANGO_NS_END
